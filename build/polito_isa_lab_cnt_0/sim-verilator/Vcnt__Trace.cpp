// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vcnt__Syms.h"


void Vcnt___024root__traceChgSub0(Vcnt___024root* vlSelf, VerilatedFst* tracep);

void Vcnt___024root__traceChgTop0(void* voidSelf, VerilatedFst* tracep) {
    Vcnt___024root* const __restrict vlSelf = static_cast<Vcnt___024root*>(voidSelf);
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vcnt___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vcnt___024root__traceChgSub0(Vcnt___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlSelf->clk_i));
        tracep->chgBit(oldp+1,(vlSelf->rst_ni));
        tracep->chgBit(oldp+2,(vlSelf->en_i));
        tracep->chgIData(oldp+3,(vlSelf->cnt_i),32);
        tracep->chgIData(oldp+4,(vlSelf->cnt_o),32);
        tracep->chgBit(oldp+5,(vlSelf->cnt_end_o));
        tracep->chgIData(oldp+6,(vlSelf->cnt__DOT__cnt_val),32);
    }
}

void Vcnt___024root__traceCleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    Vcnt___024root* const __restrict vlSelf = static_cast<Vcnt___024root*>(voidSelf);
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        __Vm_traceActivity[0U] = 0U;
    }
}
