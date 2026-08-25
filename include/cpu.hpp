#pragma once
#include "types.hpp"
#include <vector>
struct CpuState {
    u64 pc=0;
    u64 r0=0;
    bool halted=false;
};
class Cpu {
public:
    int run(const std::vector<u8>& code, CpuState& s);
};
