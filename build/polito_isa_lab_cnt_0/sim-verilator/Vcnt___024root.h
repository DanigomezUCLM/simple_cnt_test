// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcnt.h for the primary calling header

#ifndef VERILATED_VCNT___024ROOT_H_
#define VERILATED_VCNT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vcnt__Syms;
class Vcnt_VerilatedFst;


//----------

VL_MODULE(Vcnt___024root) {
  public:

    // PORTS
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(en_i,0,0);
    VL_OUT8(cnt_end_o,0,0);
    VL_IN(cnt_i,31,0);
    VL_OUT(cnt_o,31,0);

    // LOCAL SIGNALS
    IData/*31:0*/ cnt__DOT__cnt_val;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    CData/*0:0*/ __Vclklast__TOP__rst_ni;

    // INTERNAL VARIABLES
    Vcnt__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcnt___024root);  ///< Copying not allowed
  public:
    Vcnt___024root(const char* name);
    ~Vcnt___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vcnt__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
