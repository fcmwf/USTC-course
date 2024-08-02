// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VCPU__Syms.h"
#include "VCPU___024root.h"

VL_ATTR_COLD void VCPU___024root___eval_static(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_static\n"); );
}

VL_ATTR_COLD void VCPU___024root___eval_initial__TOP(VCPU___024root* vlSelf);

VL_ATTR_COLD void VCPU___024root___eval_initial(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_initial\n"); );
    // Body
    VCPU___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

void VCPU___024root____Vdpiimwrap_CPU__DOT__reg_file__DOT__set_gpr_ptr__Vdpioc2_TOP(const VlUnpacked<IData/*31:0*/, 32> &a);

VL_ATTR_COLD void VCPU___024root___eval_initial__TOP(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->commit_wb = 1U;
    vlSelf->CPU__DOT__pc__DOT__pc = 0x80000000U;
    VCPU___024root____Vdpiimwrap_CPU__DOT__reg_file__DOT__set_gpr_ptr__Vdpioc2_TOP(vlSelf->CPU__DOT__reg_file__DOT__reg_file);
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[1U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[2U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[3U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[4U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[5U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[6U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[7U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[8U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[9U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0xaU] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0xbU] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0xcU] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0xdU] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0xeU] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0xfU] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x10U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x11U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x12U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x13U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x14U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x15U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x16U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x17U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x18U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x19U] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x1aU] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x1bU] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x1cU] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x1dU] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x1eU] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__reg_file[0x1fU] = 0U;
    vlSelf->CPU__DOT__reg_file__DOT__i = 0x20U;
}

VL_ATTR_COLD void VCPU___024root___eval_final(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_final\n"); );
}

VL_ATTR_COLD void VCPU___024root___eval_triggers__stl(VCPU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__stl(VCPU___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VCPU___024root___eval_stl(VCPU___024root* vlSelf);

VL_ATTR_COLD void VCPU___024root___eval_settle(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VCPU___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VCPU___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/fcmwf/Lab2/CECS-Lab/simulator/IP/mycpu/CPU.sv", 2, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VCPU___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__stl(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VCPU___024root____Vdpiimwrap_CPU__DOT__i_cache__DOT__pmem_read_TOP(CData/*0:0*/ re, IData/*31:0*/ addr, IData/*31:0*/ mask, IData/*31:0*/ &rword);
extern const VlUnpacked<CData/*2:0*/, 32> VCPU__ConstPool__TABLE_h32b2c362_0;

VL_ATTR_COLD void VCPU___024root___stl_sequent__TOP__0(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->pc_cur = vlSelf->CPU__DOT__pc__DOT__pc;
    VCPU___024root____Vdpiimwrap_CPU__DOT__i_cache__DOT__pmem_read_TOP(1U, vlSelf->pc_cur, 3U, vlSelf->__Vtask_CPU__DOT__i_cache__DOT__pmem_read__0__rword);
    vlSelf->inst = vlSelf->__Vtask_CPU__DOT__i_cache__DOT__pmem_read__0__rword;
    vlSelf->CPU__DOT__rf_wd_sel = 0U;
    if (((0x6fU == (0x7fU & vlSelf->inst)) | (0x67U 
                                              == (0x7fU 
                                                  & vlSelf->inst)))) {
        vlSelf->CPU__DOT__rf_wd_sel = 1U;
    }
    if ((3U == (0x7fU & vlSelf->inst))) {
        vlSelf->CPU__DOT__rf_wd_sel = 2U;
    }
    vlSelf->CPU__DOT__alu_ctrl = 0U;
    if ((0x37U == (0x7fU & vlSelf->inst))) {
        vlSelf->CPU__DOT__alu_ctrl = 0x18U;
    }
    if ((0x33U == (0x7fU & vlSelf->inst))) {
        vlSelf->CPU__DOT__alu_ctrl = ((0x10U & (vlSelf->inst 
                                                >> 0x1aU)) 
                                      | ((8U & (vlSelf->inst 
                                                >> 0x16U)) 
                                         | (7U & (vlSelf->inst 
                                                  >> 0xcU))));
    }
    if ((0x13U == (0x7fU & vlSelf->inst))) {
        vlSelf->CPU__DOT__alu_ctrl = (7U & (vlSelf->inst 
                                            >> 0xcU));
    }
    if ((IData)((0x40005013U == (0xfe00707fU & vlSelf->inst)))) {
        vlSelf->CPU__DOT__alu_ctrl = 0x15U;
    }
    vlSelf->CPU__DOT__rf_rd0 = vlSelf->CPU__DOT__reg_file__DOT__reg_file
        [(0x1fU & (vlSelf->inst >> 0xfU))];
    vlSelf->CPU__DOT__rf_rd1 = vlSelf->CPU__DOT__reg_file__DOT__reg_file
        [(0x1fU & (vlSelf->inst >> 0x14U))];
    vlSelf->CPU__DOT__inst_decoder__DOT__is_i_type 
        = ((3U == (0x7fU & vlSelf->inst)) | ((0x13U 
                                              == (0x7fU 
                                                  & vlSelf->inst)) 
                                             | (0x67U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->inst))));
    vlSelf->CPU__DOT__inst_decoder__DOT__is_u_type 
        = ((0x17U == (0x7fU & vlSelf->inst)) | (0x37U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->inst)));
    vlSelf->CPU__DOT__alu_src0 = (((0x17U == (0x7fU 
                                              & vlSelf->inst)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->inst)) 
                                      | (0x63U == (0x7fU 
                                                   & vlSelf->inst))))
                                   ? vlSelf->CPU__DOT__pc__DOT__pc
                                   : vlSelf->CPU__DOT__rf_rd0);
    vlSelf->__Vtableidx1 = (((0x6fU == (0x7fU & vlSelf->inst)) 
                             << 4U) | (((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_u_type) 
                                        << 3U) | ((
                                                   (0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->inst)) 
                                                   << 2U) 
                                                  | (((0x23U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->inst)) 
                                                      << 1U) 
                                                     | (IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_i_type)))));
    vlSelf->CPU__DOT__imm_type = VCPU__ConstPool__TABLE_h32b2c362_0
        [vlSelf->__Vtableidx1];
    vlSelf->CPU__DOT__imm = ((4U & (IData)(vlSelf->CPU__DOT__imm_type))
                              ? ((2U & (IData)(vlSelf->CPU__DOT__imm_type))
                                  ? 0U : ((1U & (IData)(vlSelf->CPU__DOT__imm_type))
                                           ? (((- (IData)(
                                                          (vlSelf->inst 
                                                           >> 0x1fU))) 
                                               << 0x14U) 
                                              | ((0xff000U 
                                                  & vlSelf->inst) 
                                                 | ((0x800U 
                                                     & (vlSelf->inst 
                                                        >> 9U)) 
                                                    | (0x7feU 
                                                       & (vlSelf->inst 
                                                          >> 0x14U)))))
                                           : (0xfffff000U 
                                              & vlSelf->inst)))
                              : ((2U & (IData)(vlSelf->CPU__DOT__imm_type))
                                  ? ((1U & (IData)(vlSelf->CPU__DOT__imm_type))
                                      ? (((- (IData)(
                                                     (vlSelf->inst 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0x800U 
                                             & (vlSelf->inst 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlSelf->inst 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelf->inst 
                                                     >> 7U)))))
                                      : (((- (IData)(
                                                     (vlSelf->inst 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0xfe0U 
                                             & (vlSelf->inst 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->inst 
                                                  >> 7U)))))
                                  : ((1U & (IData)(vlSelf->CPU__DOT__imm_type))
                                      ? (((- (IData)(
                                                     (vlSelf->inst 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | (vlSelf->inst 
                                            >> 0x14U))
                                      : 0U)));
    vlSelf->CPU__DOT__alu_src1 = (((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_i_type) 
                                   | ((0x23U == (0x7fU 
                                                 & vlSelf->inst)) 
                                      | ((0x63U == 
                                          (0x7fU & vlSelf->inst)) 
                                         | ((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_u_type) 
                                            | (0x6fU 
                                               == (0x7fU 
                                                   & vlSelf->inst))))))
                                   ? vlSelf->CPU__DOT__imm
                                   : vlSelf->CPU__DOT__rf_rd1);
    vlSelf->CPU__DOT__alu__DOT__mul_res = 0ULL;
    vlSelf->CPU__DOT__alu_res = 0U;
    if ((0x10U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
        if ((8U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
            if ((4U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
                vlSelf->CPU__DOT__alu__DOT__mul_res = 0ULL;
                vlSelf->CPU__DOT__alu_res = 0U;
            } else if ((2U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
                vlSelf->CPU__DOT__alu__DOT__mul_res = 0ULL;
                vlSelf->CPU__DOT__alu_res = 0U;
            } else if ((1U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
                vlSelf->CPU__DOT__alu__DOT__mul_res = 0ULL;
                vlSelf->CPU__DOT__alu_res = 0U;
            } else {
                vlSelf->CPU__DOT__alu_res = vlSelf->CPU__DOT__alu_src1;
            }
        } else if ((4U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
            if ((2U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
                vlSelf->CPU__DOT__alu__DOT__mul_res = 0ULL;
                vlSelf->CPU__DOT__alu_res = 0U;
            } else if ((1U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
                vlSelf->CPU__DOT__alu_res = VL_SHIFTRS_III(32,32,5, vlSelf->CPU__DOT__alu_src0, 
                                                           (0x1fU 
                                                            & vlSelf->CPU__DOT__alu_src1));
            } else {
                vlSelf->CPU__DOT__alu__DOT__mul_res = 0ULL;
                vlSelf->CPU__DOT__alu_res = 0U;
            }
        } else if ((2U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
            vlSelf->CPU__DOT__alu__DOT__mul_res = 0ULL;
            vlSelf->CPU__DOT__alu_res = 0U;
        } else if ((1U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
            vlSelf->CPU__DOT__alu__DOT__mul_res = 0ULL;
            vlSelf->CPU__DOT__alu_res = 0U;
        } else {
            vlSelf->CPU__DOT__alu_res = (vlSelf->CPU__DOT__alu_src0 
                                         - vlSelf->CPU__DOT__alu_src1);
        }
    } else if ((8U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
        if ((4U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
            vlSelf->CPU__DOT__alu_res = ((2U & (IData)(vlSelf->CPU__DOT__alu_ctrl))
                                          ? ((1U & (IData)(vlSelf->CPU__DOT__alu_ctrl))
                                              ? ((0U 
                                                  == vlSelf->CPU__DOT__alu_src1)
                                                  ? vlSelf->CPU__DOT__alu_src0
                                                  : 
                                                 VL_MODDIV_III(32, vlSelf->CPU__DOT__alu_src0, vlSelf->CPU__DOT__alu_src1))
                                              : ((0U 
                                                  == vlSelf->CPU__DOT__alu_src1)
                                                  ? vlSelf->CPU__DOT__alu_src0
                                                  : 
                                                 VL_MODDIVS_III(32, vlSelf->CPU__DOT__alu_src0, vlSelf->CPU__DOT__alu_src1)))
                                          : ((1U & (IData)(vlSelf->CPU__DOT__alu_ctrl))
                                              ? ((0U 
                                                  == vlSelf->CPU__DOT__alu_src1)
                                                  ? 0xffffffffU
                                                  : 
                                                 VL_DIV_III(32, vlSelf->CPU__DOT__alu_src0, vlSelf->CPU__DOT__alu_src1))
                                              : ((0U 
                                                  == vlSelf->CPU__DOT__alu_src1)
                                                  ? 0xffffffffU
                                                  : 
                                                 (((0x80000000U 
                                                    == vlSelf->CPU__DOT__alu_src0) 
                                                   & (0xffffffffU 
                                                      == vlSelf->CPU__DOT__alu_src1))
                                                   ? 0x80000000U
                                                   : 
                                                  VL_DIVS_III(32, vlSelf->CPU__DOT__alu_src0, vlSelf->CPU__DOT__alu_src1)))));
        } else if ((2U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
            if ((1U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
                vlSelf->CPU__DOT__alu__DOT__mul_res 
                    = ((QData)((IData)(vlSelf->CPU__DOT__alu_src0)) 
                       * (QData)((IData)(vlSelf->CPU__DOT__alu_src1)));
                vlSelf->CPU__DOT__alu_res = (IData)(
                                                    (vlSelf->CPU__DOT__alu__DOT__mul_res 
                                                     >> 0x20U));
            } else {
                vlSelf->CPU__DOT__alu__DOT__mul_res 
                    = ((0x80000000U <= vlSelf->CPU__DOT__alu_src0)
                        ? (((QData)((IData)(vlSelf->CPU__DOT__alu_src0)) 
                            * (QData)((IData)(vlSelf->CPU__DOT__alu_src1))) 
                           - ((QData)((IData)(vlSelf->CPU__DOT__alu_src1)) 
                              << 0x20U)) : ((QData)((IData)(vlSelf->CPU__DOT__alu_src0)) 
                                            * (QData)((IData)(vlSelf->CPU__DOT__alu_src1))));
                vlSelf->CPU__DOT__alu_res = (IData)(
                                                    (vlSelf->CPU__DOT__alu__DOT__mul_res 
                                                     >> 0x20U));
            }
        } else if ((1U & (IData)(vlSelf->CPU__DOT__alu_ctrl))) {
            vlSelf->CPU__DOT__alu__DOT__mul_res = VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QI(64,32, vlSelf->CPU__DOT__alu_src0), 
                                                              VL_EXTENDS_QI(64,32, vlSelf->CPU__DOT__alu_src1));
            vlSelf->CPU__DOT__alu_res = (IData)((vlSelf->CPU__DOT__alu__DOT__mul_res 
                                                 >> 0x20U));
        } else {
            vlSelf->CPU__DOT__alu__DOT__mul_res = ((QData)((IData)(vlSelf->CPU__DOT__alu_src0)) 
                                                   * (QData)((IData)(vlSelf->CPU__DOT__alu_src1)));
            vlSelf->CPU__DOT__alu_res = (IData)(vlSelf->CPU__DOT__alu__DOT__mul_res);
        }
    } else {
        vlSelf->CPU__DOT__alu_res = ((4U & (IData)(vlSelf->CPU__DOT__alu_ctrl))
                                      ? ((2U & (IData)(vlSelf->CPU__DOT__alu_ctrl))
                                          ? ((1U & (IData)(vlSelf->CPU__DOT__alu_ctrl))
                                              ? (vlSelf->CPU__DOT__alu_src0 
                                                 & vlSelf->CPU__DOT__alu_src1)
                                              : (vlSelf->CPU__DOT__alu_src0 
                                                 | vlSelf->CPU__DOT__alu_src1))
                                          : ((1U & (IData)(vlSelf->CPU__DOT__alu_ctrl))
                                              ? (vlSelf->CPU__DOT__alu_src0 
                                                 >> 
                                                 (0x1fU 
                                                  & vlSelf->CPU__DOT__alu_src1))
                                              : (vlSelf->CPU__DOT__alu_src0 
                                                 ^ vlSelf->CPU__DOT__alu_src1)))
                                      : ((2U & (IData)(vlSelf->CPU__DOT__alu_ctrl))
                                          ? ((1U & (IData)(vlSelf->CPU__DOT__alu_ctrl))
                                              ? (vlSelf->CPU__DOT__alu_src0 
                                                 < vlSelf->CPU__DOT__alu_src1)
                                              : VL_LTS_III(32, vlSelf->CPU__DOT__alu_src0, vlSelf->CPU__DOT__alu_src1))
                                          : ((1U & (IData)(vlSelf->CPU__DOT__alu_ctrl))
                                              ? (vlSelf->CPU__DOT__alu_src0 
                                                 << 
                                                 (0x1fU 
                                                  & vlSelf->CPU__DOT__alu_src1))
                                              : (vlSelf->CPU__DOT__alu_src0 
                                                 + vlSelf->CPU__DOT__alu_src1))));
    }
    vlSelf->uncache_read_wb = ((3U == (0x7fU & vlSelf->inst)) 
                               & (0xaU == (vlSelf->CPU__DOT__alu_res 
                                           >> 0x1cU)));
    VCPU___024root____Vdpiimwrap_CPU__DOT__i_cache__DOT__pmem_read_TOP(
                                                                       (3U 
                                                                        == 
                                                                        (0x7fU 
                                                                         & vlSelf->inst)), vlSelf->CPU__DOT__alu_res, 
                                                                       (3U 
                                                                        & (vlSelf->inst 
                                                                           >> 0xcU)), vlSelf->__Vtask_CPU__DOT__d_cache__DOT__pmem_read__2__rword);
    vlSelf->CPU__DOT__dm_rd_raw = vlSelf->__Vtask_CPU__DOT__d_cache__DOT__pmem_read__2__rword;
    vlSelf->CPU__DOT__pc_next = ((((0x4000U & vlSelf->inst)
                                    ? ((0x2000U & vlSelf->inst)
                                        ? ((0x1000U 
                                            & vlSelf->inst)
                                            ? ((vlSelf->CPU__DOT__rf_rd0 
                                                >= vlSelf->CPU__DOT__rf_rd1) 
                                               & (0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->inst)))
                                            : ((vlSelf->CPU__DOT__rf_rd0 
                                                < vlSelf->CPU__DOT__rf_rd1) 
                                               & (0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->inst))))
                                        : ((0x1000U 
                                            & vlSelf->inst)
                                            ? (VL_GTES_III(32, vlSelf->CPU__DOT__rf_rd0, vlSelf->CPU__DOT__rf_rd1) 
                                               & (0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->inst)))
                                            : (VL_LTS_III(32, vlSelf->CPU__DOT__rf_rd0, vlSelf->CPU__DOT__rf_rd1) 
                                               & (0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->inst)))))
                                    : ((~ (vlSelf->inst 
                                           >> 0xdU)) 
                                       & ((0x1000U 
                                           & vlSelf->inst)
                                           ? ((vlSelf->CPU__DOT__rf_rd0 
                                               != vlSelf->CPU__DOT__rf_rd1) 
                                              & (0x63U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->inst)))
                                           : ((vlSelf->CPU__DOT__rf_rd0 
                                               == vlSelf->CPU__DOT__rf_rd1) 
                                              & (0x63U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->inst)))))) 
                                  | (0x6fU == (0x7fU 
                                               & vlSelf->inst)))
                                  ? vlSelf->CPU__DOT__alu_res
                                  : ((0x67U == (0x7fU 
                                                & vlSelf->inst))
                                      ? (0xfffffffeU 
                                         & vlSelf->CPU__DOT__alu_res)
                                      : ((IData)(4U) 
                                         + vlSelf->CPU__DOT__pc__DOT__pc)));
}

VL_ATTR_COLD void VCPU___024root___eval_stl(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VCPU___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__act(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__nba(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VCPU___024root___ctor_var_reset(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rstn = VL_RAND_RESET_I(1);
    vlSelf->pc_cur = VL_RAND_RESET_I(32);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->commit_wb = VL_RAND_RESET_I(1);
    vlSelf->uncache_read_wb = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__pc_next = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__imm_type = VL_RAND_RESET_I(3);
    vlSelf->CPU__DOT__alu_ctrl = VL_RAND_RESET_I(5);
    vlSelf->CPU__DOT__rf_wd_sel = VL_RAND_RESET_I(2);
    vlSelf->CPU__DOT__rf_rd0 = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__rf_rd1 = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__alu_src0 = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__alu_src1 = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__alu_res = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__dm_rd_raw = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__pc__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__inst_decoder__DOT__is_i_type = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__inst_decoder__DOT__is_u_type = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->CPU__DOT__reg_file__DOT__reg_file[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->CPU__DOT__reg_file__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__alu__DOT__mul_res = VL_RAND_RESET_Q(64);
    vlSelf->__Vtask_CPU__DOT__i_cache__DOT__pmem_read__0__rword = 0;
    vlSelf->__Vtask_CPU__DOT__d_cache__DOT__pmem_read__2__rword = 0;
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
