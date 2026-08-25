#include "cpu.hpp"
int Cpu::run(const std::vector<u8>& code,CpuState&s){
    while(!s.halted && s.pc<code.size()){
        u8 op=code[s.pc++];
        switch(op){
            case 0x00: break;
            case 0x01: s.r0++; break;
            case 0x02: s.r0+=2; break;
            case 0xff: s.halted=true; break;
            default: return -1;
        }
    }
    return 0;
}
