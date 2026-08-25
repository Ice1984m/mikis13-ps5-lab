#pragma once

#include "types.hpp"

#include <string>

struct SyscallResult
{
    bool supported = false;
    int code = -1;
    std::string message;
};

SyscallResult emulateTestSyscall(u64 number);
