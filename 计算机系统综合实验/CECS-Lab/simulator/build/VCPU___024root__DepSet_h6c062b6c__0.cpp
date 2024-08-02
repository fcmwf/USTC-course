// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VCPU__Syms.h"
#include "VCPU__Syms.h"
#include "VCPU___024root.h"

extern "C" void pmem_read(svBit re, int addr, int mask, int* rword);

VL_INLINE_OPT void VCPU___024root____Vdpiimwrap_CPU__DOT__i_cache__DOT__pmem_read_TOP(CData/*0:0*/ re, IData/*31:0*/ addr, IData/*31:0*/ mask, IData/*31:0*/ &rword) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root____Vdpiimwrap_CPU__DOT__i_cache__DOT__pmem_read_TOP\n"); );
    // Body
    svBit re__Vcvt;
    for (size_t re__Vidx = 0; re__Vidx < 1; ++re__Vidx) re__Vcvt = re;
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int mask__Vcvt;
    for (size_t mask__Vidx = 0; mask__Vidx < 1; ++mask__Vidx) mask__Vcvt = mask;
    int rword__Vcvt;
    pmem_read(re__Vcvt, addr__Vcvt, mask__Vcvt, &rword__Vcvt);
    rword = rword__Vcvt;
}

extern "C" void set_gpr_ptr(const svOpenArrayHandle a);

VL_INLINE_OPT void VCPU___024root____Vdpiimwrap_CPU__DOT__reg_file__DOT__set_gpr_ptr__Vdpioc2_TOP(const VlUnpacked<IData/*31:0*/, 32> &a) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root____Vdpiimwrap_CPU__DOT__reg_file__DOT__set_gpr_ptr__Vdpioc2_TOP\n"); );
    // Body
    static const int a__Vopenprops__ulims[2] = {0, 31};
    static const VerilatedVarProps a__Vopenprops(VLVT_UINT32, VLVD_IN, VerilatedVarProps::Packed(), 31, 0, VerilatedVarProps::Unpacked(), 1, a__Vopenprops__ulims);
    VerilatedDpiOpenVar a__Vopenarray (&a__Vopenprops, &a);
    set_gpr_ptr(&a__Vopenarray);
}

extern "C" void pmem_write(svBit we, int addr, int mask, int wword);

VL_INLINE_OPT void VCPU___024root____Vdpiimwrap_CPU__DOT__d_cache__DOT__pmem_write_TOP(CData/*0:0*/ we, IData/*31:0*/ addr, IData/*31:0*/ mask, IData/*31:0*/ wword) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root____Vdpiimwrap_CPU__DOT__d_cache__DOT__pmem_write_TOP\n"); );
    // Body
    svBit we__Vcvt;
    for (size_t we__Vidx = 0; we__Vidx < 1; ++we__Vidx) we__Vcvt = we;
    int addr__Vcvt;
    for (size_t addr__Vidx = 0; addr__Vidx < 1; ++addr__Vidx) addr__Vcvt = addr;
    int mask__Vcvt;
    for (size_t mask__Vidx = 0; mask__Vidx < 1; ++mask__Vidx) mask__Vcvt = mask;
    int wword__Vcvt;
    for (size_t wword__Vidx = 0; wword__Vidx < 1; ++wword__Vidx) wword__Vcvt = wword;
    pmem_write(we__Vcvt, addr__Vcvt, mask__Vcvt, wword__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__act(VCPU___024root* vlSelf);
#endif  // VL_DEBUG

void VCPU___024root___eval_triggers__act(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCPU___024root___dump_triggers__act(vlSelf);
    }
#endif
}
