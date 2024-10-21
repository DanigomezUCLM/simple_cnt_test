// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vcnt__Syms.h"


void Vcnt___024root__traceInitSub0(Vcnt___024root* vlSelf, VerilatedFst* tracep) VL_ATTR_COLD;

void Vcnt___024root__traceInitTop(Vcnt___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vcnt___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vcnt___024root__traceInitSub0(Vcnt___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+2,"rst_ni",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+3,"en_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+4,"cnt_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBus(c+5,"cnt_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+6,"cnt_end_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+1,"cnt clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+2,"cnt rst_ni",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+3,"cnt en_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+4,"cnt cnt_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBus(c+5,"cnt cnt_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+6,"cnt cnt_end_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+7,"cnt cnt_val",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    }
}

void Vcnt___024root__traceFullTop0(void* voidSelf, VerilatedFst* tracep) VL_ATTR_COLD;
void Vcnt___024root__traceChgTop0(void* voidSelf, VerilatedFst* tracep);
void Vcnt___024root__traceCleanup(void* voidSelf, VerilatedFst* /*unused*/);

void Vcnt___024root__traceRegister(Vcnt___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vcnt___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vcnt___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vcnt___024root__traceCleanup, vlSelf);
    }
}

void Vcnt___024root__traceFullSub0(Vcnt___024root* vlSelf, VerilatedFst* tracep) VL_ATTR_COLD;

void Vcnt___024root__traceFullTop0(void* voidSelf, VerilatedFst* tracep) {
    Vcnt___024root* const __restrict vlSelf = static_cast<Vcnt___024root*>(voidSelf);
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vcnt___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vcnt___024root__traceFullSub0(Vcnt___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcnt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->clk_i));
        tracep->fullBit(oldp+2,(vlSelf->rst_ni));
        tracep->fullBit(oldp+3,(vlSelf->en_i));
        tracep->fullIData(oldp+4,(vlSelf->cnt_i),32);
        tracep->fullIData(oldp+5,(vlSelf->cnt_o),32);
        tracep->fullBit(oldp+6,(vlSelf->cnt_end_o));
        tracep->fullIData(oldp+7,(vlSelf->cnt__DOT__cnt_val),32);
    }
}
