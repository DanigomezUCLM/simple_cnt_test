// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcnt.h for the primary calling header

#include "Vcnt___024root.h"
#include "Vcnt__Syms.h"

//==========

VL_INLINE_OPT void Vcnt___024root___sequent__TOP__1(Vcnt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt___024root___sequent__TOP__1\n"); );
    // Body
    if (vlSelf->rst_ni) {
        if (vlSelf->en_i) {
            vlSelf->cnt__DOT__cnt_val = ((IData)(1U) 
                                         + vlSelf->cnt__DOT__cnt_val);
        }
    } else {
        vlSelf->cnt__DOT__cnt_val = 0U;
    }
    vlSelf->cnt_o = vlSelf->cnt__DOT__cnt_val;
}

VL_INLINE_OPT void Vcnt___024root___combo__TOP__3(Vcnt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt___024root___combo__TOP__3\n"); );
    // Body
    vlSelf->cnt_end_o = (vlSelf->cnt__DOT__cnt_val 
                         == vlSelf->cnt_i);
}

void Vcnt___024root___eval(Vcnt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i))) 
         | ((~ (IData)(vlSelf->rst_ni)) & (IData)(vlSelf->__Vclklast__TOP__rst_ni)))) {
        Vcnt___024root___sequent__TOP__1(vlSelf);
    }
    Vcnt___024root___combo__TOP__3(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
    vlSelf->__Vclklast__TOP__rst_ni = vlSelf->rst_ni;
}

QData Vcnt___024root___change_request_1(Vcnt___024root* vlSelf);

VL_INLINE_OPT QData Vcnt___024root___change_request(Vcnt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt___024root___change_request\n"); );
    // Body
    return (Vcnt___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vcnt___024root___change_request_1(Vcnt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcnt___024root___eval_debug_assertions(Vcnt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcnt___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->en_i & 0xfeU))) {
        Verilated::overWidthError("en_i");}
}
#endif  // VL_DEBUG
