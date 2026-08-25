#pragma once
#include "types.hpp"
#include <vector>
class Memory {
public:
    explicit Memory(std::size_t size);
    bool read8(u64,u8&) const;
    bool write8(u64,u8);
    std::size_t size() const;
private:
    std::vector<u8> mem_;
};
