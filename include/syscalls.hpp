#pragma once
#include "types.hpp"
struct SysResult {
    bool supported=false;
    int result=-1;
};
SysResult syscallTest(u64);
