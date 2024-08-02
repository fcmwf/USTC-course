// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCPU.h for the primary calling header

#ifndef VERILATED_VCPU___024ROOT_H_
#define VERILATED_VCPU___024ROOT_H_  // guard

#include "verilated.h"


class VCPU__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCPU___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rstn,0,0);
    VL_OUT8(commit_wb,0,0);
    VL_OUT8(uncache_read_wb,0,0);
    CData/*2:0*/ CPU__DOT__imm_type;
    CData/*4:0*/ CPU__DOT__alu_ctrl;
    CData/*1:0*/ CPU__DOT__rf_wd_sel;
    CData/*0:0*/ CPU__DOT__inst_decoder__DOT__is_i_type;
    CData/*0:0*/ CPU__DOT__inst_decoder__DOT__is_u_type;
    CData/*4:0*/ __Vtableidx1;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT(pc_cur,31,0);
    VL_OUT(inst,31,0);
    IData/*31:0*/ CPU__DOT__pc_next;
    IData/*31:0*/ CPU__DOT__rf_rd0;
    IData/*31:0*/ CPU__DOT__rf_rd1;
    IData/*31:0*/ CPU__DOT__imm;
    IData/*31:0*/ CPU__DOT__alu_src0;
    IData/*31:0*/ CPU__DOT__alu_src1;
    IData/*31:0*/ CPU__DOT__alu_res;
    IData/*31:0*/ CPU__DOT__dm_rd_raw;
    IData/*31:0*/ CPU__DOT__pc__DOT__pc;
    IData/*31:0*/ CPU__DOT__reg_file__DOT__i;
    IData/*31:0*/ __Vtask_CPU__DOT__i_cache__DOT__pmem_read__0__rword;
    IData/*31:0*/ __Vtask_CPU__DOT__d_cache__DOT__pmem_read__2__rword;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ CPU__DOT__alu__DOT__mul_res;
    VlUnpacked<IData/*31:0*/, 32> CPU__DOT__reg_file__DOT__reg_file;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VCPU__Syms* const vlSymsp;

    // CONSTRUCTORS
    VCPU___024root(VCPU__Syms* symsp, const char* v__name);
    ~VCPU___024root();
    VL_UNCOPYABLE(VCPU___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
