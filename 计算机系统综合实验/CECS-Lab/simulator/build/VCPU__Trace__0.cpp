// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VCPU__Syms.h"


void VCPU___024root__trace_chg_sub_0(VCPU___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VCPU___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_chg_top_0\n"); );
    // Init
    VCPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU___024root*>(voidSelf);
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VCPU___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VCPU___024root__trace_chg_sub_0(VCPU___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->CPU__DOT__reg_file__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+1,(vlSelf->CPU__DOT__imm_type),3);
        bufp->chgCData(oldp+2,(vlSelf->CPU__DOT__alu_ctrl),5);
        bufp->chgCData(oldp+3,(vlSelf->CPU__DOT__rf_wd_sel),2);
        bufp->chgIData(oldp+4,(vlSelf->CPU__DOT__rf_rd0),32);
        bufp->chgIData(oldp+5,(vlSelf->CPU__DOT__rf_rd1),32);
        bufp->chgIData(oldp+6,(vlSelf->CPU__DOT__imm),32);
        bufp->chgIData(oldp+7,(vlSelf->CPU__DOT__alu_src0),32);
        bufp->chgIData(oldp+8,(vlSelf->CPU__DOT__alu_src1),32);
        bufp->chgIData(oldp+9,(vlSelf->CPU__DOT__alu_res),32);
        bufp->chgIData(oldp+10,(((IData)(4U) + vlSelf->CPU__DOT__pc__DOT__pc)),32);
        bufp->chgIData(oldp+11,((0xfffffffeU & vlSelf->CPU__DOT__alu_res)),32);
        bufp->chgIData(oldp+12,(vlSelf->CPU__DOT__dm_rd_raw),32);
        bufp->chgQData(oldp+13,(vlSelf->CPU__DOT__alu__DOT__mul_res),64);
        bufp->chgBit(oldp+15,(vlSelf->CPU__DOT__inst_decoder__DOT__is_i_type));
        bufp->chgBit(oldp+16,(vlSelf->CPU__DOT__inst_decoder__DOT__is_u_type));
        bufp->chgIData(oldp+17,(vlSelf->CPU__DOT__pc__DOT__pc),32);
        bufp->chgIData(oldp+18,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[0]),32);
        bufp->chgIData(oldp+19,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[1]),32);
        bufp->chgIData(oldp+20,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[2]),32);
        bufp->chgIData(oldp+21,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[3]),32);
        bufp->chgIData(oldp+22,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[4]),32);
        bufp->chgIData(oldp+23,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[5]),32);
        bufp->chgIData(oldp+24,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[6]),32);
        bufp->chgIData(oldp+25,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[7]),32);
        bufp->chgIData(oldp+26,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[8]),32);
        bufp->chgIData(oldp+27,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[9]),32);
        bufp->chgIData(oldp+28,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[10]),32);
        bufp->chgIData(oldp+29,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[11]),32);
        bufp->chgIData(oldp+30,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[12]),32);
        bufp->chgIData(oldp+31,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[13]),32);
        bufp->chgIData(oldp+32,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[14]),32);
        bufp->chgIData(oldp+33,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[15]),32);
        bufp->chgIData(oldp+34,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[16]),32);
        bufp->chgIData(oldp+35,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[17]),32);
        bufp->chgIData(oldp+36,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[18]),32);
        bufp->chgIData(oldp+37,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[19]),32);
        bufp->chgIData(oldp+38,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[20]),32);
        bufp->chgIData(oldp+39,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[21]),32);
        bufp->chgIData(oldp+40,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[22]),32);
        bufp->chgIData(oldp+41,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[23]),32);
        bufp->chgIData(oldp+42,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[24]),32);
        bufp->chgIData(oldp+43,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[25]),32);
        bufp->chgIData(oldp+44,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[26]),32);
        bufp->chgIData(oldp+45,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[27]),32);
        bufp->chgIData(oldp+46,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[28]),32);
        bufp->chgIData(oldp+47,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[29]),32);
        bufp->chgIData(oldp+48,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[30]),32);
        bufp->chgIData(oldp+49,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[31]),32);
    }
    bufp->chgBit(oldp+50,(vlSelf->clk));
    bufp->chgBit(oldp+51,(vlSelf->rstn));
    bufp->chgIData(oldp+52,(vlSelf->pc_cur),32);
    bufp->chgIData(oldp+53,(vlSelf->inst),32);
    bufp->chgBit(oldp+54,(vlSelf->commit_wb));
    bufp->chgBit(oldp+55,(vlSelf->uncache_read_wb));
    bufp->chgIData(oldp+56,(((((0x4000U & vlSelf->inst)
                                ? ((0x2000U & vlSelf->inst)
                                    ? ((0x1000U & vlSelf->inst)
                                        ? ((vlSelf->CPU__DOT__rf_rd0 
                                            >= vlSelf->CPU__DOT__rf_rd1) 
                                           & (0x63U 
                                              == (0x7fU 
                                                  & vlSelf->inst)))
                                        : ((vlSelf->CPU__DOT__rf_rd0 
                                            < vlSelf->CPU__DOT__rf_rd1) 
                                           & (0x63U 
                                              == (0x7fU 
                                                  & vlSelf->inst))))
                                    : ((0x1000U & vlSelf->inst)
                                        ? (VL_GTES_III(32, vlSelf->CPU__DOT__rf_rd0, vlSelf->CPU__DOT__rf_rd1) 
                                           & (0x63U 
                                              == (0x7fU 
                                                  & vlSelf->inst)))
                                        : (VL_LTS_III(32, vlSelf->CPU__DOT__rf_rd0, vlSelf->CPU__DOT__rf_rd1) 
                                           & (0x63U 
                                              == (0x7fU 
                                                  & vlSelf->inst)))))
                                : ((~ (vlSelf->inst 
                                       >> 0xdU)) & 
                                   ((0x1000U & vlSelf->inst)
                                     ? ((vlSelf->CPU__DOT__rf_rd0 
                                         != vlSelf->CPU__DOT__rf_rd1) 
                                        & (0x63U == 
                                           (0x7fU & vlSelf->inst)))
                                     : ((vlSelf->CPU__DOT__rf_rd0 
                                         == vlSelf->CPU__DOT__rf_rd1) 
                                        & (0x63U == 
                                           (0x7fU & vlSelf->inst)))))) 
                              | (0x6fU == (0x7fU & vlSelf->inst)))
                              ? vlSelf->CPU__DOT__alu_res
                              : ((0x67U == (0x7fU & vlSelf->inst))
                                  ? (0xfffffffeU & vlSelf->CPU__DOT__alu_res)
                                  : ((IData)(4U) + vlSelf->CPU__DOT__pc__DOT__pc)))),32);
    bufp->chgBit(oldp+57,(((0x17U == (0x7fU & vlSelf->inst)) 
                           | ((0x6fU == (0x7fU & vlSelf->inst)) 
                              | (0x63U == (0x7fU & vlSelf->inst))))));
    bufp->chgBit(oldp+58,(((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_i_type) 
                           | ((0x23U == (0x7fU & vlSelf->inst)) 
                              | ((0x63U == (0x7fU & vlSelf->inst)) 
                                 | ((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_u_type) 
                                    | (0x6fU == (0x7fU 
                                                 & vlSelf->inst))))))));
    bufp->chgCData(oldp+59,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->chgBit(oldp+60,((0x63U == (0x7fU & vlSelf->inst))));
    bufp->chgBit(oldp+61,((0x6fU == (0x7fU & vlSelf->inst))));
    bufp->chgBit(oldp+62,((0x67U == (0x7fU & vlSelf->inst))));
    bufp->chgBit(oldp+63,(((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_u_type) 
                           | ((0x6fU == (0x7fU & vlSelf->inst)) 
                              | ((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_i_type) 
                                 | (0x33U == (0x7fU 
                                              & vlSelf->inst)))))));
    bufp->chgBit(oldp+64,((0x23U == (0x7fU & vlSelf->inst))));
    bufp->chgCData(oldp+65,((0x1fU & (vlSelf->inst 
                                      >> 0xfU))),5);
    bufp->chgCData(oldp+66,((0x1fU & (vlSelf->inst 
                                      >> 0x14U))),5);
    bufp->chgCData(oldp+67,((0x1fU & (vlSelf->inst 
                                      >> 7U))),5);
    bufp->chgIData(oldp+68,(((2U & (IData)(vlSelf->CPU__DOT__rf_wd_sel))
                              ? ((1U & (IData)(vlSelf->CPU__DOT__rf_wd_sel))
                                  ? 0U : ((0x4000U 
                                           & vlSelf->inst)
                                           ? ((0x2000U 
                                               & vlSelf->inst)
                                               ? 0U
                                               : ((0x1000U 
                                                   & vlSelf->inst)
                                                   ? 
                                                  (0xffffU 
                                                   & vlSelf->CPU__DOT__dm_rd_raw)
                                                   : 
                                                  (0xffU 
                                                   & vlSelf->CPU__DOT__dm_rd_raw)))
                                           : ((0x2000U 
                                               & vlSelf->inst)
                                               ? ((0x1000U 
                                                   & vlSelf->inst)
                                                   ? 0U
                                                   : vlSelf->CPU__DOT__dm_rd_raw)
                                               : ((0x1000U 
                                                   & vlSelf->inst)
                                                   ? 
                                                  (((- (IData)(
                                                               (1U 
                                                                & (vlSelf->CPU__DOT__dm_rd_raw 
                                                                   >> 0xfU)))) 
                                                    << 0x10U) 
                                                   | (0xffffU 
                                                      & vlSelf->CPU__DOT__dm_rd_raw))
                                                   : 
                                                  (((- (IData)(
                                                               (1U 
                                                                & (vlSelf->CPU__DOT__dm_rd_raw 
                                                                   >> 7U)))) 
                                                    << 8U) 
                                                   | (0xffU 
                                                      & vlSelf->CPU__DOT__dm_rd_raw))))))
                              : ((1U & (IData)(vlSelf->CPU__DOT__rf_wd_sel))
                                  ? ((IData)(4U) + vlSelf->CPU__DOT__pc__DOT__pc)
                                  : vlSelf->CPU__DOT__alu_res))),32);
    bufp->chgBit(oldp+69,(((0x4000U & vlSelf->inst)
                            ? ((0x2000U & vlSelf->inst)
                                ? ((0x1000U & vlSelf->inst)
                                    ? ((vlSelf->CPU__DOT__rf_rd0 
                                        >= vlSelf->CPU__DOT__rf_rd1) 
                                       & (0x63U == 
                                          (0x7fU & vlSelf->inst)))
                                    : ((vlSelf->CPU__DOT__rf_rd0 
                                        < vlSelf->CPU__DOT__rf_rd1) 
                                       & (0x63U == 
                                          (0x7fU & vlSelf->inst))))
                                : ((0x1000U & vlSelf->inst)
                                    ? (VL_GTES_III(32, vlSelf->CPU__DOT__rf_rd0, vlSelf->CPU__DOT__rf_rd1) 
                                       & (0x63U == 
                                          (0x7fU & vlSelf->inst)))
                                    : (VL_LTS_III(32, vlSelf->CPU__DOT__rf_rd0, vlSelf->CPU__DOT__rf_rd1) 
                                       & (0x63U == 
                                          (0x7fU & vlSelf->inst)))))
                            : ((~ (vlSelf->inst >> 0xdU)) 
                               & ((0x1000U & vlSelf->inst)
                                   ? ((vlSelf->CPU__DOT__rf_rd0 
                                       != vlSelf->CPU__DOT__rf_rd1) 
                                      & (0x63U == (0x7fU 
                                                   & vlSelf->inst)))
                                   : ((vlSelf->CPU__DOT__rf_rd0 
                                       == vlSelf->CPU__DOT__rf_rd1) 
                                      & (0x63U == (0x7fU 
                                                   & vlSelf->inst))))))));
    bufp->chgIData(oldp+70,(((0x4000U & vlSelf->inst)
                              ? ((0x2000U & vlSelf->inst)
                                  ? 0U : ((0x1000U 
                                           & vlSelf->inst)
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
                                          << 8U) | 
                                         (0xffU & vlSelf->CPU__DOT__dm_rd_raw)))))),32);
    bufp->chgBit(oldp+71,((3U == (0x7fU & vlSelf->inst))));
    bufp->chgCData(oldp+72,((3U & (vlSelf->inst >> 0xcU))),2);
    bufp->chgCData(oldp+73,((0x7fU & vlSelf->inst)),7);
    bufp->chgCData(oldp+74,((vlSelf->inst >> 0x19U)),7);
    bufp->chgBit(oldp+75,((0x33U == (0x7fU & vlSelf->inst))));
    bufp->chgBit(oldp+76,((0x13U == (0x7fU & vlSelf->inst))));
    bufp->chgBit(oldp+77,((0x17U == (0x7fU & vlSelf->inst))));
    bufp->chgBit(oldp+78,((0x37U == (0x7fU & vlSelf->inst))));
}

void VCPU___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_cleanup\n"); );
    // Init
    VCPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU___024root*>(voidSelf);
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
