#pragma once

#include <string>
#include <vector>

class Debugger
{
public:
    void log(const std::string& message);

    const std::vector<std::string>&
    entries() const;

private:
    std::vector<std::string> entries_;
};
