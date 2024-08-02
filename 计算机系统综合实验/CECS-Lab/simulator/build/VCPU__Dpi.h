// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VCPU__DPI_H_
#define VERILATED_VCPU__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/fcmwf/Lab2/CECS-Lab/simulator/IP/mycpu/I_CACHE.sv:12:34
    extern void pmem_read(svBit re, int addr, int mask, int* rword);
    // DPI import at /home/fcmwf/Lab2/CECS-Lab/simulator/IP/mycpu/D_CACHE.sv:17:34
    extern void pmem_write(svBit we, int addr, int mask, int wword);
    // DPI import at /home/fcmwf/Lab2/CECS-Lab/simulator/IP/mycpu/REG_FILE.sv:11:34
    extern void set_gpr_ptr(const svOpenArrayHandle a);

#ifdef __cplusplus
}
#endif

#endif  // guard
