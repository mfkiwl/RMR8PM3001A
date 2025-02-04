#pragma once
//
// RISC-V Instruction Set Architecture 
//
// Extension RV64M
//

#ifndef __INCLUDE_RV64M
#define __INCLUDE_RV64M
#endif

#include "riscvdef.hpp"
#include "riscv_32m.hpp"


// Function-3
#define RV64M_FUNCT3_MASK                       0x00007000
#define RV64M_FUNCT3_OFFSET                     12

#define RV64M_FUNCT3_MULW                       0b000
#define RV64M_FUNCT3_DIVW                       0b100
#define RV64M_FUNCT3_DIVUW                      0b101
#define RV64M_FUNCT3_REMW                       0b110
#define RV64M_FUNCT3_REMUW                      0b111


// Function-7
#define RV64M_FUNCT7_MASK                       0xFE000000
#define RV64M_FUNCT7_OFFSET                     25

#define RV64M_FUNCT7_MULW                       0b0000001
#define RV64M_FUNCT7_DIVW                       0b0000001
#define RV64M_FUNCT7_DIVUW                      0b0000001
#define RV64M_FUNCT7_REMW                       0b0000001
#define RV64M_FUNCT7_REMUW                      0b0000001


