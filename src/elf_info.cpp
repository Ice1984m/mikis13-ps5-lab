#include "elf_info.hpp"

#include <array>
#include <fstream>

ElfInfo inspectElf(const std::string& path)
{
    ElfInfo out;

    std::ifstream f(path, std::ios::binary);

    if (!f)
        return out;

    std::array<unsigned char, 20> h{};

    f.read(
        reinterpret_cast<char*>(h.data()),
        static_cast<std::streamsize>(h.size())
    );

    if (f.gcount() < 20)
        return out;

    if (
        h[0] != 0x7f ||
        h[1] != 'E' ||
        h[2] != 'L' ||
        h[3] != 'F'
    )
        return out;

    out.valid = true;
    out.is64 = h[4] == 2;
    out.littleEndian = h[5] == 1;

    const unsigned machine =
        static_cast<unsigned>(h[18]) |
        (static_cast<unsigned>(h[19]) << 8);

    switch (machine)
    {
        case 62:
            out.machine = "x86_64";
            break;

        case 183:
            out.machine = "AArch64";
            break;

        default:
            out.machine = "unknown";
            break;
    }

    return out;
}
