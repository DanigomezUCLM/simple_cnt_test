// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcnt.h"
#include "Vcnt__Syms.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vcnt::Vcnt(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vcnt__Syms(_vcontextp__, _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , en_i{vlSymsp->TOP.en_i}
    , cnt_i{vlSymsp->TOP.cnt_i}
    , cnt_o{vlSymsp->TOP.cnt_o}
    , cnt_end_o{vlSymsp->TOP.cnt_end_o}
    , rootp{&(vlSymsp->TOP)}
{
}

Vcnt::Vcnt(const char* _vcname__)
    : Vcnt(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vcnt::~Vcnt() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vcnt___024root___eval_initial(Vcnt___024root* vlSelf);
void Vcnt___024root___eval_settle(Vcnt___024root* vlSelf);
void Vcnt___024root___eval(Vcnt___024root* vlSelf);
QData Vcnt___024root___change_request(Vcnt___024root* vlSelf);
#ifdef VL_DEBUG
void Vcnt___024root___eval_debug_assertions(Vcnt___024root* vlSelf);
#endif  // VL_DEBUG
void Vcnt___024root___final(Vcnt___024root* vlSelf);

static void _eval_initial_loop(Vcnt__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vcnt___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vcnt___024root___eval_settle(&(vlSymsp->TOP));
        Vcnt___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vcnt___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../../../rtl/cnt.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vcnt___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcnt::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcnt::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcnt___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vcnt___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vcnt___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../../../rtl/cnt.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vcnt___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vcnt::final() {
    Vcnt___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vcnt::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vcnt::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vcnt___024root__traceInitTop(Vcnt___024root* vlSelf, VerilatedFst* tracep);

static void traceInit(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcnt___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcnt___024root*>(voidSelf);
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vcnt___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vcnt___024root__traceRegister(Vcnt___024root* vlSelf, VerilatedFst* tracep);

void Vcnt::trace(VerilatedFstC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    Vcnt___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
