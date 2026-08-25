#include "syscalls.hpp"
SysResult syscallTest(u64 n){
    if(n==0) return {true,0};
    if(n==1) return {true,1};
    return {false,-1};
}
