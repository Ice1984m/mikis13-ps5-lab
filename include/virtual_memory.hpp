#pragma once

#include "types.hpp"

#include <cstddef>
#include <vector>

class VirtualMemory
{
public:
    explicit VirtualMemory(std::size_t size);

    bool write8(u64 address, u8 value);
    bool read8(u64 address, u8& value) const;

    std::size_t size() const;

private:
    std::vector<u8> memory_;
};
