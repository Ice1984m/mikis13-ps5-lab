#include "debugger.hpp"
#include "decoder.hpp"
#include "elf_info.hpp"
#include "gpu.hpp"
#include "input.hpp"
#include "shader.hpp"
#include "syscall.hpp"
#include "virtual_memory.hpp"

#include <filesystem>
#include <iostream>
#include <string>

static void banner()
{
    std::cout
        << "\n"
        << "========================================\n"
        << " Mikis13 PS5 Emulator Research Lab V3\n"
        << "========================================\n\n";
}

static void help()
{
    std::cout
        << "Gebruik:\n\n"
        << "  mikis13-ps5 info\n"
        << "  mikis13-ps5 selftest\n"
        << "  mikis13-ps5 inspect <test.elf>\n"
        << "  mikis13-ps5 run <homebrew.elf>\n\n"
        << "Deze V3 is een emulator research core.\n"
        << "Geen firmware, keys of DRM bypass inbegrepen.\n";
}

static int selftest()
{
    VirtualMemory memory(1024);

    if (!memory.write8(10, 0x42))
        return 1;

    u8 value = 0;

    if (!memory.read8(10, value))
        return 2;

    if (value != 0x42)
        return 3;

    auto decoded = decodeTestOpcode(0x02);

    if (!decoded.valid)
        return 4;

    auto syscall = emulateTestSyscall(1);

    if (!syscall.supported)
        return 5;

    GpuQueue gpu;
    gpu.push({"CLEAR_COLOR"});
    gpu.push({"DRAW_TEST_TRIANGLE"});

    if (gpu.size() != 2)
        return 6;

    auto shader = translateTestShader(
        "test shader"
    );

    if (!shader.accepted)
        return 7;

    auto controller = neutralController();

    if (controller.cross)
        return 8;

    Debugger debugger;
    debugger.log("selftest");

    if (debugger.entries().empty())
        return 9;

    std::cout
        << "✅ memory\n"
        << "✅ decoder\n"
        << "✅ syscall abstraction\n"
        << "✅ gpu queue\n"
        << "✅ shader abstraction\n"
        << "✅ controller abstraction\n"
        << "✅ debugger\n";

    return 0;
}

int main(int argc, char** argv)
{
    banner();

    if (argc < 2)
    {
        help();
        return 0;
    }

    const std::string cmd = argv[1];

    if (cmd == "info")
    {
        std::cout
            << "ELF loader: working inspector\n"
            << "Virtual memory: prototype working\n"
            << "Instruction decoder: test ISA working\n"
            << "Syscall abstraction: prototype working\n"
            << "GPU queue: prototype working\n"
            << "Shader translation: abstraction stage\n"
            << "Controller input: abstraction stage\n"
            << "Debugger: prototype working\n"
            << "Commercial PS5 games: not supported\n";

        return 0;
    }

    if (cmd == "selftest")
        return selftest();

    if (
        cmd == "inspect" ||
        cmd == "run"
    )
    {
        if (argc < 3)
        {
            std::cerr
                << "❌ Geen ELF opgegeven\n";
            return 2;
        }

        const std::string path = argv[2];

        if (!std::filesystem::exists(path))
        {
            std::cerr
                << "❌ Bestand ontbreekt\n";
            return 3;
        }

        const ElfInfo info =
            inspectElf(path);

        if (!info.valid)
        {
            std::cerr
                << "❌ Geen geldige ELF\n";
            return 4;
        }

        std::cout
            << "✅ ELF geldig\n"
            << "64-bit: "
            << (info.is64 ? "ja" : "nee")
            << "\n"
            << "Machine: "
            << info.machine
            << "\n";

        if (cmd == "run")
        {
            std::cout
                << "\n"
                << "Loader stage bereikt.\n"
                << "Guest execution van echte PS5 software "
                << "is nog niet geïmplementeerd.\n";
        }

        return 0;
    }

    help();
    return 1;
}
