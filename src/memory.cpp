#include "memory.hpp"
Memory::Memory(std::size_t s):mem_(s,0){}
bool Memory::read8(u64 a,u8&v)const{
    if(a>=mem_.size()) return false;
    v=mem_[a]; return true;
}
bool Memory::write8(u64 a,u8 v){
    if(a>=mem_.size()) return false;
    mem_[a]=v; return true;
}
std::size_t Memory::size()const{return mem_.size();}
