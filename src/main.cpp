#include "elf.hpp"
#include "memory.hpp"
#include "cpu.hpp"
#include "scheduler.hpp"
#include "syscalls.hpp"
#include "gpu.hpp"
#include "input.hpp"
#include "audio.hpp"
#include "debugger.hpp"

#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

static int selftest(){
    Memory m(4096);
    if(!m.write8(10,0x42)) return 1;
    u8 v=0;
    if(!m.read8(10,v)||v!=0x42) return 2;

    Cpu cpu;
    CpuState s;
    std::vector<u8> code={0x01,0x02,0xff};
    if(cpu.run(code,s)!=0 || s.r0!=3) return 3;

    Scheduler sc;
    sc.add();
    if(sc.count()!=1) return 4;

    if(!syscallTest(1).supported) return 5;

    GpuQueue gpu;
    gpu.push("CLEAR");
    gpu.push("DRAW_TEST");
    if(gpu.size()!=2) return 6;

    Audio a;
    a.submit(512);
    if(a.submitted()!=512) return 7;

    auto pad=neutralPad();
    if(pad.cross) return 8;

    Debugger d;
    d.log("boot");
    if(d.count()!=1) return 9;

    std::cout
      <<"✅ memory\n"
      <<"✅ cpu interpreter\n"
      <<"✅ scheduler\n"
      <<"✅ syscalls\n"
      <<"✅ gpu queue\n"
      <<"✅ audio\n"
      <<"✅ input\n"
      <<"✅ debugger\n";
    return 0;
}

int main(int argc,char**argv){
    std::cout<<"Mikis13 PS5 Lab V4\n";

    if(argc<2){
        std::cout<<"info | selftest | inspect <file.elf> | run <homebrew.elf>\n";
        return 0;
    }

    std::string c=argv[1];

    if(c=="info"){
        std::cout
          <<"ELF inspector: working\n"
          <<"Memory: working prototype\n"
          <<"CPU: test interpreter working\n"
          <<"Scheduler: working prototype\n"
          <<"Syscalls: test abstraction working\n"
          <<"GPU: command abstraction working\n"
          <<"Audio/input/debugger: prototype working\n"
          <<"Retail PS5 games: not supported\n";
        return 0;
    }

    if(c=="selftest")
        return selftest();

    if(c=="inspect"||c=="run"){
        if(argc<3) return 2;
        std::string path=argv[2];
        if(!std::filesystem::exists(path)) return 3;

        auto e=inspectElf(path);
        if(!e.valid){
            std::cerr<<"❌ invalid ELF\n";
            return 4;
        }

        std::cout<<"✅ ELF "<<e.machine
                 <<" 64bit="<<(e.is64?"yes":"no")<<"\n";

        if(c=="run"){
            std::cout
              <<"Loader accepted homebrew/test ELF.\n"
              <<"Real PS5 guest execution is not implemented.\n";
        }
        return 0;
    }

    return 1;
}
