#include "elf_info.hpp"

#include <filesystem>
#include <iostream>
#include <string>

static void banner()
{
    std::cout
        << "\n"
        << "========================================\n"
        << " Mikis13 PS5 Emulator Research Lab V2\n"
        << "========================================\n\n";
}

static void help()
{
    std::cout
        << "Gebruik:\n\n"
        << "  mikis13-ps5 info\n"
        << "  mikis13-ps5 inspect <bestand.elf>\n"
        << "  mikis13-ps5 run <homebrew.elf>\n\n"
        << "V2 voert nog geen commerciële PS5-games uit.\n"
        << "Alleen homebrew en test-ELF worden geaccepteerd.\n";
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
            << "Core: V2 research shell\n"
            << "ELF loader: inspector stage\n"
            << "CPU translation: planned\n"
            << "Memory manager: planned\n"
            << "Graphics: Vulkan planned\n"
            << "Audio: planned\n"
            << "Input: planned\n";

        return 0;
    }

    if (cmd == "inspect" || cmd == "run")
    {
        if (argc < 3)
        {
            std::cerr << "❌ Geen ELF-bestand opgegeven\n";
            return 2;
        }

        const std::string path = argv[2];

        if (!std::filesystem::exists(path))
        {
            std::cerr << "❌ Bestand bestaat niet\n";
            return 3;
        }

        const ElfInfo info = inspectElf(path);

        if (!info.valid)
        {
            std::cerr << "❌ Geen geldige ELF\n";
            return 4;
        }

        std::cout
            << "✅ Geldige ELF\n"
            << "64-bit: "
            << (info.is64 ? "ja" : "nee")
            << "\n"
            << "Endian: "
            << (info.littleEndian ? "little" : "other")
            << "\n"
            << "Machine: "
            << info.machine
            << "\n";

        if (cmd == "run")
        {
            std::cout
                << "\n"
                << "Research execution stage bereikt.\n"
                << "Deze V2 executeert guest-code nog niet.\n";
        }

        return 0;
    }

    help();

    return 1;
}
