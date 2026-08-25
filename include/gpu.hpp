#pragma once

#include <string>
#include <vector>

struct GpuCommand
{
    std::string name;
};

class GpuQueue
{
public:
    void push(const GpuCommand& command);

    std::size_t size() const;

    const std::vector<GpuCommand>& commands() const;

private:
    std::vector<GpuCommand> commands_;
};
