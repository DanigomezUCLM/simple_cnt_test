// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcnt.h for the primary calling header

#include "Vcnt___024root.h"
#include "Vcnt__Syms.h"

//==========


void Vcnt___024root___ctor_var_reset(Vcnt___024root* vlSelf);

Vcnt___024root::Vcnt___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vcnt___024root___ctor_var_reset(this);
}

void Vcnt___024root::__Vconfigure(Vcnt__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vcnt___024root::~Vcnt___024root() {
}

void Vcnt___024root___settle__TOP__2(Vcnt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt___024root___settle__TOP__2\n"); );
    // Body
    vlSelf->cnt_o = vlSelf->cnt__DOT__cnt_val;
    vlSelf->cnt_end_o = (vlSelf->cnt__DOT__cnt_val 
                         == vlSelf->cnt_i);
}

void Vcnt___024root___eval_initial(Vcnt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rst_ni = vlSelf->rst_ni;
}

void Vcnt___024root___eval_settle(Vcnt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt___024root___eval_settle\n"); );
    // Body
    Vcnt___024root___settle__TOP__2(vlSelf);
}

void Vcnt___024root___final(Vcnt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt___024root___final\n"); );
}

void Vcnt___024root___ctor_var_reset(Vcnt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->en_i = VL_RAND_RESET_I(1);
    vlSelf->cnt_i = VL_RAND_RESET_I(32);
    vlSelf->cnt_o = VL_RAND_RESET_I(32);
    vlSelf->cnt_end_o = VL_RAND_RESET_I(1);
    vlSelf->cnt__DOT__cnt_val = VL_RAND_RESET_I(32);
}
