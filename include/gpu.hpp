#pragma once
#include <string>
#include <vector>
class GpuQueue {
public:
    void push(std::string);
    std::size_t size() const;
private:
    std::vector<std::string> q_;
};
