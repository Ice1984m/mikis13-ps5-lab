#pragma once
#include <string>
#include <vector>
class Debugger {
public:
    void log(const std::string&);
    std::size_t count() const;
private:
    std::vector<std::string> logs_;
};
