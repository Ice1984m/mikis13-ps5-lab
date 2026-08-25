#pragma once

#include <cstdint>
#include <string>

struct ElfInfo {
    bool valid = false;
    bool is64 = false;
    bool littleEndian = false;
    std::string machine;
};

ElfInfo inspectElf(const std::string& path);
