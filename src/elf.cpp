#include "elf.hpp"
#include <array>
#include <fstream>
ElfInfo inspectElf(const std::string& path){
    ElfInfo o;
    std::ifstream f(path,std::ios::binary);
    if(!f) return o;
    std::array<unsigned char,20> h{};
    f.read((char*)h.data(),h.size());
    if(f.gcount()<20) return o;
    if(h[0]!=0x7f||h[1]!='E'||h[2]!='L'||h[3]!='F') return o;
    o.valid=true;
    o.is64=h[4]==2;
    unsigned m=h[18]|(h[19]<<8);
    if(m==62) o.machine="x86_64";
    else if(m==183) o.machine="AArch64";
    else o.machine="unknown";
    return o;
}
