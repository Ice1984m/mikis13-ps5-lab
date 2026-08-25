#include "debugger.hpp"

void Debugger::log(
    const std::string& message
)
{
    entries_.push_back(message);
}

const std::vector<std::string>&
Debugger::entries() const
{
    return entries_;
}
