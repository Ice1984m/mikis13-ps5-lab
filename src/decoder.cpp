#include "decoder.hpp"

DecodedInstruction decodeTestOpcode(u8 opcode)
{
    DecodedInstruction out;
    out.opcode = opcode;

    switch (opcode)
    {
        case 0x00:
            out.valid = true;
            out.mnemonic = "NOP";
            break;

        case 0x01:
            out.valid = true;
            out.mnemonic = "MOV_TEST";
            break;

        case 0x02:
            out.valid = true;
            out.mnemonic = "ADD_TEST";
            break;

        case 0xff:
            out.valid = true;
            out.mnemonic = "HALT_TEST";
            break;

        default:
            out.valid = false;
            out.mnemonic = "UNKNOWN";
            break;
    }

    return out;
}
