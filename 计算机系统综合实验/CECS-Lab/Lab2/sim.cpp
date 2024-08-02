#include "verilated_dpi.h"
#include "VCPU.h"
#include "verilated_vcd_c.h"
#include <bits/stdc++.h>
#include "include/debug.h"
#include "include/common.h"
#include "include/disasm.h"
#include "memory/paddr.h"

using namespace std;

extern VCPU *dut;
extern uint64_t sim_time;
extern VerilatedVcdC *m_trace;

extern uint8_t pmem[];

void print_itrace();
void difftest_step();


// Lab2 HINT: instruction log struct for instruction trace
struct inst_log{
  word_t pc;
  word_t inst;
};
inst_log inst_trace[16];
unsigned int ptr_trace = 0;

uint32_t *cpu_mstatus = NULL, *cpu_mtvec = NULL, *cpu_mepc = NULL, *cpu_mcause = NULL;
// load the state of your simulated cpu into sim_cpu
void set_state() {
  sim_cpu.pc = dut->pc_cur;
  memcpy(&sim_cpu.gpr[0], cpu_gpr, 4 * 32);
  // Lab4 TODO: set the state of csr to sim_cpu
  
}

// num of executed instruction
uint64_t g_nr_guest_inst = 0;

// simulate a single cycle
void single_cycle() {
// Lab2 TODO: implement the single cycle function of your cpu
  dut->clk = 1;
  dut->eval();
  dut->clk = 0;
  dut->eval();
  // m_trace->dump(sim_time++); 
  if(dut->commit_wb == 1) set_state();
}

// simulate a reset
void reset(int n) {
  dut->clk = 0;
  dut->rstn = 0;
  dut->eval();
  while (n-- > 0) {
    single_cycle();
  }
  dut->rstn = 1;
  dut->eval();
}

// check if the program should end
inline bool test_break(){
  return dut->inst == 0x00100073U;
}

static void statistic() {
  Log("total guest instructions = %ld", g_nr_guest_inst);
}



void device_update();
// init the running state of our simulator
SimState sim_state = { .state = SIM_STOP };

// execute n instructions
void cpu_exec(unsigned int n){
  switch (sim_state.state) {
    case SIM_END:   
    case SIM_ABORT: 
    case SIM_QUIT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: sim_state.state = SIM_RUNNING;
  }
  // Lab2 TODO: implement instruction trace for your cpu
  bool npc_cpu_uncache_pre = 0;
  while (n--) {
    //printf("n=%d\n",n);
    inst_trace[ptr_trace].pc   = dut->pc_cur;
    inst_trace[ptr_trace].inst = dut->inst;
    //printf("pc:%x  inst:%x\n",inst_trace[ptr_trace].pc,inst_trace[ptr_trace].inst);
    ptr_trace = (ptr_trace+1)%16;

    // execute single instruction
    if(test_break()) {
      // set the end state
      sim_state.halt_pc = dut->pc_cur;
      sim_state.halt_ret = cpu_gpr[10];
      sim_state.state = SIM_END;
      break;
    }

    if (dut->commit_wb) {
      if(npc_cpu_uncache_pre){
        difftest_sync();
      }
      // Lab3 TODO: use difftest_step function here to execute difftest
      
      g_nr_guest_inst++;
      npc_cpu_uncache_pre = dut->uncache_read_wb;
    }
    // your cpu step a cycle
    single_cycle();

#ifdef DEVICE
    device_update();
#endif
    if(sim_state.state != SIM_RUNNING) break;
  }

  switch (sim_state.state) {
    case SIM_RUNNING: 
      sim_state.state = SIM_STOP; break;
    case SIM_END:  
    case SIM_ABORT:
      print_itrace();
      Log("sim: %s at pc = " FMT_WORD,
          (sim_state.state == SIM_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (sim_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          sim_state.halt_pc);
      // fall through
    case SIM_QUIT: statistic();
  }
}

static const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

// map the name of reg to its value
word_t isa_reg_str2val(const char *s, bool *success) {;
  if(!strcmp(s, "pc")){
    *success = true;
    return dut->pc_cur;
  }
  for(int i = 0; i < 32; i++){
    if(!strcmp(s, regs[i])){
      *success = true;
      return cpu_gpr[i];
    }
  }
  *success = false;
  return 0;
}

// set cpu_gpr point to your cpu's gpr
extern "C" void set_gpr_ptr(const svOpenArrayHandle r) {
  cpu_gpr = (uint32_t *)(((VerilatedDpiOpenVar*)r)->datap());
}
// set the pointers pint to you cpu's csr
extern "C" void set_csr_ptr(const svOpenArrayHandle mstatus, const svOpenArrayHandle mtvec, const svOpenArrayHandle mepc, const svOpenArrayHandle mcause) {
  cpu_mstatus = (uint32_t *)(((VerilatedDpiOpenVar*)mstatus)->datap());
  cpu_mtvec = (uint32_t *)(((VerilatedDpiOpenVar*)mtvec)->datap());
  cpu_mepc = (uint32_t *)(((VerilatedDpiOpenVar*)mepc)->datap());
  cpu_mcause = (uint32_t *)(((VerilatedDpiOpenVar*)mcause)->datap());
}

void isa_reg_display() {
  for (int i = 0; i < 32; i++) {
    printf("gpr[%d](%s) = 0x%x\n", i, regs[i], cpu_gpr[i]);
  }
}

unsigned char* itoa(int num,unsigned char* str,int radix)
{
    char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";//索引表
    unsigned unum;//存放要转换的整数的绝对值,转换的整数可能是负数
    int i=0,j,k;//i用来指示设置字符串相应位，转换之后i其实就是字符串的长度；转换后顺序是逆序的，有正负的情况，k用来指示调整顺序的开始位置;j用来指示调整顺序时的交换。
 
    //获取要转换的整数的绝对值
    if(radix==10&&num<0)//要转换成十进制数并且是负数
    {
        unum=(unsigned)-num;//将num的绝对值赋给unum
        str[i++]='-';//在字符串最前面设置为'-'号，并且索引加1
    }
    else unum=(unsigned)num;//若是num为正，直接赋值给unum
 
    //转换部分，注意转换后是逆序的
    do
    {
        str[i++]=index[unum%(unsigned)radix];//取unum的最后一位，并设置为str对应位，指示索引加1
        unum/=radix;//unum去掉最后一位
 
    }while(unum);//直至unum为0退出循环
 
    str[i]='\0';//在字符串最后添加'\0'字符，c语言字符串以'\0'结束。
 
    //将顺序调整过来
    if(str[0]=='-') k=1;//如果是负数，符号不用调整，从符号后面开始调整
    else k=0;//不是负数，全部都要调整
 
    char temp;//临时变量，交换两个值时用到
    for(j=k;j<=(i-1)/2;j++)//头尾一一对称交换，i其实就是字符串的长度，索引最大值比长度少1
    {
        temp=str[j];//头部赋值给临时变量
        str[j]=str[i-1+k-j];//尾部赋值给头部
        str[i-1+k-j]=temp;//将临时变量的值(其实就是之前的头部值)赋给尾部
    }
 
    return str;//返回转换后的字符串
 
}


void print_itrace() {
  char buff[50];
  unsigned char num[50];
  // Lab2 HINT: you can implement this function to help you print the instruction trace
  for(int i=0;i<16;i++){
    itoa(inst_trace[i].inst,num,10);
    disassemble(buff,50,inst_trace[i].pc,num,4);
    printf("pc:%x  inst:%x\ncode:%s\n",inst_trace[i].pc,inst_trace[i].inst,buff);
  }
}