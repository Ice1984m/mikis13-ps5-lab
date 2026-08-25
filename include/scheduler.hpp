#pragma once
#include <cstddef>
class Scheduler {
public:
    void add();
    std::size_t count() const;
private:
    std::size_t threads_=0;
};
