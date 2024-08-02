// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VCPU__Syms.h"


VL_ATTR_COLD void VCPU___024root__trace_init_sub__TOP__0(VCPU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+51,"clk", false,-1);
    tracep->declBit(c+52,"rstn", false,-1);
    tracep->declBus(c+53,"pc_cur", false,-1, 31,0);
    tracep->declBus(c+54,"inst", false,-1, 31,0);
    tracep->declBit(c+55,"commit_wb", false,-1);
    tracep->declBit(c+56,"uncache_read_wb", false,-1);
    tracep->pushNamePrefix("CPU ");
    tracep->declBus(c+80,"PC_RST", false,-1, 31,0);
    tracep->declBus(c+81,"I_CACHE_DEPTH", false,-1, 31,0);
    tracep->declBus(c+81,"D_CACHE_DEPTH", false,-1, 31,0);
    tracep->declBit(c+51,"clk", false,-1);
    tracep->declBit(c+52,"rstn", false,-1);
    tracep->declBus(c+53,"pc_cur", false,-1, 31,0);
    tracep->declBus(c+54,"inst", false,-1, 31,0);
    tracep->declBit(c+55,"commit_wb", false,-1);
    tracep->declBit(c+56,"uncache_read_wb", false,-1);
    tracep->declBus(c+57,"pc_next", false,-1, 31,0);
    tracep->declBus(c+2,"imm_type", false,-1, 2,0);
    tracep->declBit(c+58,"alu_src0_sel", false,-1);
    tracep->declBit(c+59,"alu_src1_sel", false,-1);
    tracep->declBus(c+3,"alu_ctrl", false,-1, 4,0);
    tracep->declBus(c+60,"br_type", false,-1, 2,0);
    tracep->declBit(c+61,"br_en", false,-1);
    tracep->declBit(c+62,"jal", false,-1);
    tracep->declBit(c+63,"jalr", false,-1);
    tracep->declBit(c+64,"rf_we", false,-1);
    tracep->declBus(c+4,"rf_wd_sel", false,-1, 1,0);
    tracep->declBus(c+60,"dm_type", false,-1, 2,0);
    tracep->declBit(c+65,"dm_we_raw", false,-1);
    tracep->declBus(c+66,"rf_ra0", false,-1, 4,0);
    tracep->declBus(c+67,"rf_ra1", false,-1, 4,0);
    tracep->declBus(c+68,"rf_wa", false,-1, 4,0);
    tracep->declBus(c+69,"rf_wd", false,-1, 31,0);
    tracep->declBus(c+5,"rf_rd0", false,-1, 31,0);
    tracep->declBus(c+6,"rf_rd1", false,-1, 31,0);
    tracep->declBus(c+7,"imm", false,-1, 31,0);
    tracep->declBus(c+8,"alu_src0", false,-1, 31,0);
    tracep->declBus(c+9,"alu_src1", false,-1, 31,0);
    tracep->declBus(c+10,"alu_res", false,-1, 31,0);
    tracep->declBit(c+70,"br", false,-1);
    tracep->declBus(c+11,"pc_add4", false,-1, 31,0);
    tracep->declBus(c+10,"pc_jal_br", false,-1, 31,0);
    tracep->declBus(c+12,"pc_jalr", false,-1, 31,0);
    tracep->declBus(c+13,"dm_rd_raw", false,-1, 31,0);
    tracep->declBus(c+71,"dm_rd", false,-1, 31,0);
    tracep->declBus(c+6,"dm_wd", false,-1, 31,0);
    tracep->declBus(c+10,"dm_addr", false,-1, 31,0);
    tracep->declBit(c+65,"dm_we", false,-1);
    tracep->declBit(c+72,"dm_re", false,-1);
    tracep->declBus(c+73,"mask", false,-1, 1,0);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+8,"alu_src0", false,-1, 31,0);
    tracep->declBus(c+9,"alu_src1", false,-1, 31,0);
    tracep->declBus(c+3,"alu_ctrl", false,-1, 4,0);
    tracep->declBus(c+10,"alu_res", false,-1, 31,0);
    tracep->declQuad(c+14,"mul_res", false,-1, 63,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alu_sel0 ");
    tracep->declBus(c+5,"src0", false,-1, 31,0);
    tracep->declBus(c+53,"src1", false,-1, 31,0);
    tracep->declBit(c+58,"sel", false,-1);
    tracep->declBus(c+8,"res", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alu_sel1 ");
    tracep->declBus(c+6,"src0", false,-1, 31,0);
    tracep->declBus(c+7,"src1", false,-1, 31,0);
    tracep->declBit(c+59,"sel", false,-1);
    tracep->declBus(c+9,"res", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("branch ");
    tracep->declBus(c+60,"br_type", false,-1, 2,0);
    tracep->declBit(c+61,"br_en", false,-1);
    tracep->declBus(c+5,"rf_rd0", false,-1, 31,0);
    tracep->declBus(c+6,"rf_rd1", false,-1, 31,0);
    tracep->declBit(c+70,"br", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("d_cache ");
    tracep->declBus(c+81,"DEPTH", false,-1, 31,0);
    tracep->declBit(c+51,"clk", false,-1);
    tracep->declBus(c+10,"addr", false,-1, 31,0);
    tracep->declBus(c+6,"wd", false,-1, 31,0);
    tracep->declBit(c+65,"we", false,-1);
    tracep->declBit(c+72,"re", false,-1);
    tracep->declBus(c+73,"mask", false,-1, 1,0);
    tracep->declBus(c+13,"rd", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("d_cache_ctrl ");
    tracep->declBus(c+81,"DEPTH", false,-1, 31,0);
    tracep->declBus(c+10,"addr_raw", false,-1, 31,0);
    tracep->declBus(c+6,"wd_raw", false,-1, 31,0);
    tracep->declBus(c+13,"rd_raw", false,-1, 31,0);
    tracep->declBit(c+65,"we_raw", false,-1);
    tracep->declBus(c+60,"dm_type", false,-1, 2,0);
    tracep->declBus(c+10,"addr", false,-1, 31,0);
    tracep->declBus(c+6,"wd", false,-1, 31,0);
    tracep->declBus(c+71,"rd", false,-1, 31,0);
    tracep->declBit(c+65,"we", false,-1);
    tracep->declBus(c+73,"mask", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i_cache ");
    tracep->declBus(c+81,"DEPTH", false,-1, 31,0);
    tracep->declBus(c+53,"addr", false,-1, 31,0);
    tracep->declBus(c+54,"inst", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("imm_gen ");
    tracep->declBus(c+54,"inst", false,-1, 31,0);
    tracep->declBus(c+2,"imm_type", false,-1, 2,0);
    tracep->declBus(c+7,"imm", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("inst_decoder ");
    tracep->declBus(c+54,"inst", false,-1, 31,0);
    tracep->declBus(c+2,"imm_type", false,-1, 2,0);
    tracep->declBit(c+58,"alu_src0_sel", false,-1);
    tracep->declBit(c+59,"alu_src1_sel", false,-1);
    tracep->declBus(c+3,"alu_ctrl", false,-1, 4,0);
    tracep->declBus(c+60,"br_type", false,-1, 2,0);
    tracep->declBit(c+61,"br_en", false,-1);
    tracep->declBit(c+62,"jal", false,-1);
    tracep->declBit(c+63,"jalr", false,-1);
    tracep->declBit(c+64,"rf_we", false,-1);
    tracep->declBus(c+4,"rf_wd_sel", false,-1, 1,0);
    tracep->declBus(c+60,"dm_type", false,-1, 2,0);
    tracep->declBit(c+65,"dm_we_raw", false,-1);
    tracep->declBit(c+72,"dm_re_raw", false,-1);
    tracep->declBus(c+74,"opcode", false,-1, 6,0);
    tracep->declBus(c+60,"funct3", false,-1, 2,0);
    tracep->declBus(c+75,"funct7", false,-1, 6,0);
    tracep->declBit(c+76,"is_r_type", false,-1);
    tracep->declBit(c+16,"is_i_type", false,-1);
    tracep->declBit(c+65,"is_s_type", false,-1);
    tracep->declBit(c+61,"is_b_type", false,-1);
    tracep->declBit(c+17,"is_u_type", false,-1);
    tracep->declBit(c+62,"is_j_type", false,-1);
    tracep->declBit(c+72,"is_load", false,-1);
    tracep->declBit(c+77,"is_i_basic", false,-1);
    tracep->declBit(c+63,"is_jalr", false,-1);
    tracep->declBit(c+78,"is_auipc", false,-1);
    tracep->declBit(c+79,"is_lui", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("npc_sel ");
    tracep->declBit(c+62,"jal", false,-1);
    tracep->declBit(c+63,"jalr", false,-1);
    tracep->declBit(c+70,"br", false,-1);
    tracep->declBus(c+11,"pc_add4", false,-1, 31,0);
    tracep->declBus(c+10,"pc_jal_br", false,-1, 31,0);
    tracep->declBus(c+12,"pc_jalr", false,-1, 31,0);
    tracep->declBus(c+57,"pc_next", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc ");
    tracep->declBus(c+80,"PC_RST", false,-1, 31,0);
    tracep->declBit(c+51,"clk", false,-1);
    tracep->declBit(c+52,"rstn", false,-1);
    tracep->declBus(c+57,"pc_next", false,-1, 31,0);
    tracep->declBus(c+53,"pc_cur", false,-1, 31,0);
    tracep->declBus(c+18,"pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("reg_file ");
    tracep->declBit(c+51,"clk", false,-1);
    tracep->declBus(c+66,"rf_ra0", false,-1, 4,0);
    tracep->declBus(c+67,"rf_ra1", false,-1, 4,0);
    tracep->declBus(c+68,"rf_wa", false,-1, 4,0);
    tracep->declBit(c+64,"rf_we", false,-1);
    tracep->declBus(c+69,"rf_wd", false,-1, 31,0);
    tracep->declBus(c+5,"rf_rd0", false,-1, 31,0);
    tracep->declBus(c+6,"rf_rd1", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+19+i*1,"reg_file", true,(i+0), 31,0);
    }
    tracep->declBus(c+1,"i", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("rf_sel ");
    tracep->declBus(c+10,"src0", false,-1, 31,0);
    tracep->declBus(c+11,"src1", false,-1, 31,0);
    tracep->declBus(c+71,"src2", false,-1, 31,0);
    tracep->declBus(c+82,"src3", false,-1, 31,0);
    tracep->declBus(c+4,"sel", false,-1, 1,0);
    tracep->declBus(c+69,"res", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void VCPU___024root__trace_init_top(VCPU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_init_top\n"); );
    // Body
    VCPU___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VCPU___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VCPU___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VCPU___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VCPU___024root__trace_register(VCPU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VCPU___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VCPU___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VCPU___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VCPU___024root__trace_full_sub_0(VCPU___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VCPU___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_full_top_0\n"); );
    // Init
    VCPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU___024root*>(voidSelf);
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VCPU___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VCPU___024root__trace_full_sub_0(VCPU___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->CPU__DOT__reg_file__DOT__i),32);
    bufp->fullCData(oldp+2,(vlSelf->CPU__DOT__imm_type),3);
    bufp->fullCData(oldp+3,(vlSelf->CPU__DOT__alu_ctrl),5);
    bufp->fullCData(oldp+4,(vlSelf->CPU__DOT__rf_wd_sel),2);
    bufp->fullIData(oldp+5,(vlSelf->CPU__DOT__rf_rd0),32);
    bufp->fullIData(oldp+6,(vlSelf->CPU__DOT__rf_rd1),32);
    bufp->fullIData(oldp+7,(vlSelf->CPU__DOT__imm),32);
    bufp->fullIData(oldp+8,(vlSelf->CPU__DOT__alu_src0),32);
    bufp->fullIData(oldp+9,(vlSelf->CPU__DOT__alu_src1),32);
    bufp->fullIData(oldp+10,(vlSelf->CPU__DOT__alu_res),32);
    bufp->fullIData(oldp+11,(((IData)(4U) + vlSelf->CPU__DOT__pc__DOT__pc)),32);
    bufp->fullIData(oldp+12,((0xfffffffeU & vlSelf->CPU__DOT__alu_res)),32);
    bufp->fullIData(oldp+13,(vlSelf->CPU__DOT__dm_rd_raw),32);
    bufp->fullQData(oldp+14,(vlSelf->CPU__DOT__alu__DOT__mul_res),64);
    bufp->fullBit(oldp+16,(vlSelf->CPU__DOT__inst_decoder__DOT__is_i_type));
    bufp->fullBit(oldp+17,(vlSelf->CPU__DOT__inst_decoder__DOT__is_u_type));
    bufp->fullIData(oldp+18,(vlSelf->CPU__DOT__pc__DOT__pc),32);
    bufp->fullIData(oldp+19,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[0]),32);
    bufp->fullIData(oldp+20,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[1]),32);
    bufp->fullIData(oldp+21,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[2]),32);
    bufp->fullIData(oldp+22,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[3]),32);
    bufp->fullIData(oldp+23,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[4]),32);
    bufp->fullIData(oldp+24,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[5]),32);
    bufp->fullIData(oldp+25,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[6]),32);
    bufp->fullIData(oldp+26,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[7]),32);
    bufp->fullIData(oldp+27,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[8]),32);
    bufp->fullIData(oldp+28,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[9]),32);
    bufp->fullIData(oldp+29,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[10]),32);
    bufp->fullIData(oldp+30,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[11]),32);
    bufp->fullIData(oldp+31,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[12]),32);
    bufp->fullIData(oldp+32,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[13]),32);
    bufp->fullIData(oldp+33,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[14]),32);
    bufp->fullIData(oldp+34,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[15]),32);
    bufp->fullIData(oldp+35,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[16]),32);
    bufp->fullIData(oldp+36,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[17]),32);
    bufp->fullIData(oldp+37,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[18]),32);
    bufp->fullIData(oldp+38,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[19]),32);
    bufp->fullIData(oldp+39,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[20]),32);
    bufp->fullIData(oldp+40,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[21]),32);
    bufp->fullIData(oldp+41,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[22]),32);
    bufp->fullIData(oldp+42,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[23]),32);
    bufp->fullIData(oldp+43,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[24]),32);
    bufp->fullIData(oldp+44,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[25]),32);
    bufp->fullIData(oldp+45,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[26]),32);
    bufp->fullIData(oldp+46,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[27]),32);
    bufp->fullIData(oldp+47,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[28]),32);
    bufp->fullIData(oldp+48,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[29]),32);
    bufp->fullIData(oldp+49,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[30]),32);
    bufp->fullIData(oldp+50,(vlSelf->CPU__DOT__reg_file__DOT__reg_file[31]),32);
    bufp->fullBit(oldp+51,(vlSelf->clk));
    bufp->fullBit(oldp+52,(vlSelf->rstn));
    bufp->fullIData(oldp+53,(vlSelf->pc_cur),32);
    bufp->fullIData(oldp+54,(vlSelf->inst),32);
    bufp->fullBit(oldp+55,(vlSelf->commit_wb));
    bufp->fullBit(oldp+56,(vlSelf->uncache_read_wb));
    bufp->fullIData(oldp+57,(((((0x4000U & vlSelf->inst)
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
                                            (0x7fU 
                                             & vlSelf->inst)))
                                      : ((vlSelf->CPU__DOT__rf_rd0 
                                          == vlSelf->CPU__DOT__rf_rd1) 
                                         & (0x63U == 
                                            (0x7fU 
                                             & vlSelf->inst)))))) 
                               | (0x6fU == (0x7fU & vlSelf->inst)))
                               ? vlSelf->CPU__DOT__alu_res
                               : ((0x67U == (0x7fU 
                                             & vlSelf->inst))
                                   ? (0xfffffffeU & vlSelf->CPU__DOT__alu_res)
                                   : ((IData)(4U) + vlSelf->CPU__DOT__pc__DOT__pc)))),32);
    bufp->fullBit(oldp+58,(((0x17U == (0x7fU & vlSelf->inst)) 
                            | ((0x6fU == (0x7fU & vlSelf->inst)) 
                               | (0x63U == (0x7fU & vlSelf->inst))))));
    bufp->fullBit(oldp+59,(((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_i_type) 
                            | ((0x23U == (0x7fU & vlSelf->inst)) 
                               | ((0x63U == (0x7fU 
                                             & vlSelf->inst)) 
                                  | ((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_u_type) 
                                     | (0x6fU == (0x7fU 
                                                  & vlSelf->inst))))))));
    bufp->fullCData(oldp+60,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullBit(oldp+61,((0x63U == (0x7fU & vlSelf->inst))));
    bufp->fullBit(oldp+62,((0x6fU == (0x7fU & vlSelf->inst))));
    bufp->fullBit(oldp+63,((0x67U == (0x7fU & vlSelf->inst))));
    bufp->fullBit(oldp+64,(((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_u_type) 
                            | ((0x6fU == (0x7fU & vlSelf->inst)) 
                               | ((IData)(vlSelf->CPU__DOT__inst_decoder__DOT__is_i_type) 
                                  | (0x33U == (0x7fU 
                                               & vlSelf->inst)))))));
    bufp->fullBit(oldp+65,((0x23U == (0x7fU & vlSelf->inst))));
    bufp->fullCData(oldp+66,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+67,((0x1fU & (vlSelf->inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+68,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->fullIData(oldp+69,(((2U & (IData)(vlSelf->CPU__DOT__rf_wd_sel))
                               ? ((1U & (IData)(vlSelf->CPU__DOT__rf_wd_sel))
                                   ? 0U : ((0x4000U 
                                            & vlSelf->inst)
                                            ? ((0x2000U 
                                                & vlSelf->inst)
                                                ? 0U
                                                : (
                                                   (0x1000U 
                                                    & vlSelf->inst)
                                                    ? 
                                                   (0xffffU 
                                                    & vlSelf->CPU__DOT__dm_rd_raw)
                                                    : 
                                                   (0xffU 
                                                    & vlSelf->CPU__DOT__dm_rd_raw)))
                                            : ((0x2000U 
                                                & vlSelf->inst)
                                                ? (
                                                   (0x1000U 
                                                    & vlSelf->inst)
                                                    ? 0U
                                                    : vlSelf->CPU__DOT__dm_rd_raw)
                                                : (
                                                   (0x1000U 
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
    bufp->fullBit(oldp+70,(((0x4000U & vlSelf->inst)
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
                                       & (0x63U == 
                                          (0x7fU & vlSelf->inst)))
                                    : ((vlSelf->CPU__DOT__rf_rd0 
                                        == vlSelf->CPU__DOT__rf_rd1) 
                                       & (0x63U == 
                                          (0x7fU & vlSelf->inst))))))));
    bufp->fullIData(oldp+71,(((0x4000U & vlSelf->inst)
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
    bufp->fullBit(oldp+72,((3U == (0x7fU & vlSelf->inst))));
    bufp->fullCData(oldp+73,((3U & (vlSelf->inst >> 0xcU))),2);
    bufp->fullCData(oldp+74,((0x7fU & vlSelf->inst)),7);
    bufp->fullCData(oldp+75,((vlSelf->inst >> 0x19U)),7);
    bufp->fullBit(oldp+76,((0x33U == (0x7fU & vlSelf->inst))));
    bufp->fullBit(oldp+77,((0x13U == (0x7fU & vlSelf->inst))));
    bufp->fullBit(oldp+78,((0x17U == (0x7fU & vlSelf->inst))));
    bufp->fullBit(oldp+79,((0x37U == (0x7fU & vlSelf->inst))));
    bufp->fullIData(oldp+80,(0x80000000U),32);
    bufp->fullIData(oldp+81,(8U),32);
    bufp->fullIData(oldp+82,(0U),32);
}
