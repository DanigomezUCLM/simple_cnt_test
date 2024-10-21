#include <iostream>

// Verilator libraries
#include <verilated.h>
#include <verilated_fst_c.h>

// DUT header
#include "Vcnt.h"

// Defines
// -------
#define FST_FILENAME "logs/waves.fst"
#define PRE_RESET_CYCLES 200
#define RESET_CYCLES 200
#define POST_RESET_CYCLES 50
#define MAX_SIM_CYCLES 2e6
#define RUN_CYCLES 500
#define TB_HIER_NAME "TOP.cnt"

// Generate clock and reset
void clkGen(Vcnt *dut);
void rstDut(Vcnt *dut, uint8_t gen_waves, VerilatedFstC *trace);

// Run a number of cycles
void runCycles(unsigned int ncycles, Vcnt *dut, uint8_t gen_waves, VerilatedFstC *trace);

vluint64_t sim_cycles = 0;

int main()
{
    bool gen_waves = true;

    // Create Verilator simulation context
    VerilatedContext *cntx = new VerilatedContext;

    if (gen_waves)
    {
        Verilated::mkdir("logs");
        cntx->traceEverOn(true);
    }

    // Instantiate DUT
    Vcnt *dut = new Vcnt(cntx);

    // Set the file to store the waveforms in
    VerilatedFstC *trace = NULL;
    if (gen_waves)
    {
        trace = new VerilatedFstC;
        dut->trace(trace, 10);
        trace->open(FST_FILENAME);
    }

    rstDut(dut, gen_waves, trace);

    // Set the DUT stimuli
    dut->cnt_i = RUN_CYCLES;
    dut->en_i = 1;

    // Run simulation
    runCycles(RUN_CYCLES, dut, gen_waves, trace);

    // Check the output
    if (dut->cnt_o != RUN_CYCLES)
    {
        std::cout << "Simulation failed: expected " << RUN_CYCLES << " but got " << dut->cnt_o << std::endl;
    } else {
        std::cout << "Simulation passed: expected " << RUN_CYCLES << " and got " << dut->cnt_o << std::endl;
    }

    // CLEAN UP
    // --------
    // Simulation complete
    dut->final();

    // Clean up and exit
    if (gen_waves)
        trace->close();
    delete dut;
    delete cntx;
}

void clkGen(Vcnt *dut)
{
    dut->clk_i ^= 1;
}

void rstDut(Vcnt *dut, uint8_t gen_waves, VerilatedFstC *trace)
{
    dut->rst_ni = 1;
    runCycles(PRE_RESET_CYCLES, dut, gen_waves, trace);
    dut->rst_ni = 0;
    runCycles(RESET_CYCLES, dut, gen_waves, trace);
    dut->rst_ni = 1;
    runCycles(POST_RESET_CYCLES, dut, gen_waves, trace);
}

void runCycles(unsigned int ncycles, Vcnt *dut, uint8_t gen_waves, VerilatedFstC *trace)
{
    VerilatedContext *cntx = dut->contextp();
    for (unsigned int i = 0; i < (2 * ncycles); i++)
    {
        // Generate clock
        clkGen(dut);

        // Evaluate the DUT
        dut->eval();

        // Save waveforms
        if (gen_waves)
            trace->dump(cntx->time());
        if (dut->clk_i == 1)
            sim_cycles++;
        cntx->timeInc(1);
    }
}
