#pragma once

#include "types.hpp"

#include <string>

struct DecodedInstruction
{
    bool valid = false;
    std::string mnemonic;
    u8 opcode = 0;
};

DecodedInstruction decodeTestOpcode(u8 opcode);
