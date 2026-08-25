#include "syscall.hpp"

SyscallResult emulateTestSyscall(u64 number)
{
    switch (number)
    {
        case 0:
            return {
                true,
                0,
                "test-null"
            };

        case 1:
            return {
                true,
                0,
                "test-log"
            };

        default:
            return {
                false,
                -1,
                "unsupported"
            };
    }
}
