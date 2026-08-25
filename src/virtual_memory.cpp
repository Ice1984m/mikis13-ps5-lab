#include "virtual_memory.hpp"

VirtualMemory::VirtualMemory(std::size_t size)
    : memory_(size, 0)
{
}

bool VirtualMemory::write8(u64 address, u8 value)
{
    if (address >= memory_.size())
        return false;

    memory_[static_cast<std::size_t>(address)] = value;
    return true;
}

bool VirtualMemory::read8(u64 address, u8& value) const
{
    if (address >= memory_.size())
        return false;

    value = memory_[static_cast<std::size_t>(address)];
    return true;
}

std::size_t VirtualMemory::size() const
{
    return memory_.size();
}
