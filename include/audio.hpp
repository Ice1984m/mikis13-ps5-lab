#pragma once
#include <cstddef>
class Audio {
public:
    void submit(std::size_t frames);
    std::size_t submitted() const;
private:
    std::size_t frames_=0;
};
