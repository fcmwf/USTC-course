// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VCPU__Syms.h"
#include "VCPU___024root.h"

void VCPU___024root___eval_act(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_act\n"); );
}

void VCPU___024root____Vdpiimwrap_CPU__DOT__d_cache__DOT__pmem_write_TOP(CData/*0:0*/ we, IData/*31:0*/ addr, IData/*31:0*/ mask, IData/*31:0*/ wword);
void VCPU___024root____Vdpiimwrap_CPU__DOT__i_cache__DOT__pmem_read_TOP(CData/*0:0*/ re, IData/*31:0*/ addr, IData/*31:0*/ mask, IData/*31:0*/ &rword);
extern const VlUnpacked<CData/*2:0*/, 32> VCPU__ConstPool__TABLE_h32b2c362_0;

VL_INLINE_OPT void VCPU___024root___nba_sequent__TOP__0(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__CPU__DOT__reg_file__DOT__reg_file__v0;
    __Vdlyvdim0__CPU__DOT__reg_file__DOT__reg_file__v0 = 0;
    IData/*31:0*/ __Vdlyvval__CPU__DOT__reg_file__DOT__reg_file__v0;
    __Vdlyvval__CPU__DOT__reg_file__DOT__reg_file__v0 = 0;
    CData/*0:0*/ __Vdlyvset__CPU__DOT__reg_file__DOT__reg_file__v0;
    __Vdlyvset__CPU__DOT__reg_file__DOT__reg_file__v0 = 0;
    // Body
    if ((0x23U == (0x7fU & vlSelf->inst))) {
        VCPU___024root____Vdpiimwrap_CPU__DOT__d_cache__DOT__pmem_write_TOP(
                                                                            (0x23U 
                                                                             == 
                                                                             (0x7fU 
                                                                              & vlSelf->inst)), vlSelf->CPU__DOT__alu_res, 
                                                                            (3U 
                                                                             & (vlSelf->inst 
                                                                                >> 0xcU)), vlSelf->CPU__DOT__rf_rd1);
    }
    __Vdlyvset__CPU__DOT__reg_file__DOT__reg_file__v0 = 0U;
    if ((((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_u_type) 
          | ((0x6fU == (0x7fU & vlSelf->inst)) | ((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_i_type) 
                                                  | (0x33U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->inst))))) 
         & (0U != (0x1fU & (vlSelf->inst >> 7U))))) {
        __Vdlyvval__CPU__DOT__reg_file__DOT__reg_file__v0 
            = ((2U & (IData)(vlSelf->CPU__DOT__rf_wd_sel))
                ? ((1U & (IData)(vlSelf->CPU__DOT__rf_wd_sel))
                    ? 0U : ((0x4000U & vlSelf->inst)
                             ? ((0x2000U & vlSelf->inst)
                                 ? 0U : ((0x1000U & vlSelf->inst)
                                          ? (0xffffU 
                                             & vlSelf->CPU__DOT__dm_rd_raw)
                                          : (0xffU 
                                             & vlSelf->CPU__DOT__dm_rd_raw)))
                             : ((0x2000U & vlSelf->inst)
                                 ? ((0x1000U & vlSelf->inst)
                                     ? 0U : vlSelf->CPU__DOT__dm_rd_raw)
                                 : ((0x1000U & vlSelf->inst)
                                     ? (((- (IData)(
                                                    (1U 
                                                     & (vlSelf->CPU__DOT__dm_rd_raw 
                                                        >> 0xfU)))) 
                                         << 0x10U) 
                                        | (0xffffU 
                                           & vlSelf->CPU__DOT__dm_rd_raw))
                                     : (((- (IData)(
                                                    (1U 
                                                     & (vlSelf->CPU__DOT__dm_rd_raw 
                                                        >> 7U)))) 
                                         << 8U) | (0xffU 
                                                   & vlSelf->CPU__DOT__dm_rd_raw))))))
                : ((1U & (IData)(vlSelf->CPU__DOT__rf_wd_sel))
                    ? ((IData)(4U) + vlSelf->CPU__DOT__pc__DOT__pc)
                    : vlSelf->CPU__DOT__alu_res));
        __Vdlyvset__CPU__DOT__reg_file__DOT__reg_file__v0 = 1U;
        __Vdlyvdim0__CPU__DOT__reg_file__DOT__reg_file__v0 
            = (0x1fU & (vlSelf->inst >> 7U));
    }
    if (__Vdlyvset__CPU__DOT__reg_file__DOT__reg_file__v0) {
        vlSelf->CPU__DOT__reg_file__DOT__reg_file[__Vdlyvdim0__CPU__DOT__reg_file__DOT__reg_file__v0] 
            = __Vdlyvval__CPU__DOT__reg_file__DOT__reg_file__v0;
    }
    vlSelf->CPU__DOT__pc__DOT__pc = ((IData)(vlSelf->rstn)
                                      ? vlSelf->CPU__DOT__pc_next
                                      : 0x80000000U);
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

void VCPU___024root___eval_nba(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VCPU___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VCPU___024root___eval_triggers__act(VCPU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__act(VCPU___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__nba(VCPU___024root* vlSelf);
#endif  // VL_DEBUG

void VCPU___024root___eval(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VCPU___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VCPU___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/fcmwf/Lab2/CECS-Lab/simulator/IP/mycpu/CPU.sv", 2, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                VCPU___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VCPU___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/fcmwf/Lab2/CECS-Lab/simulator/IP/mycpu/CPU.sv", 2, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VCPU___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VCPU___024root___eval_debug_assertions(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rstn & 0xfeU))) {
        Verilated::overWidthError("rstn");}
}
#endif  // VL_DEBUG
