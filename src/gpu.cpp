#include "gpu.hpp"

void GpuQueue::push(const GpuCommand& command)
{
    commands_.push_back(command);
}

std::size_t GpuQueue::size() const
{
    return commands_.size();
}

const std::vector<GpuCommand>&
GpuQueue::commands() const
{
    return commands_;
}
