#include "gpu.hpp"
void GpuQueue::push(std::string s){q_.push_back(std::move(s));}
std::size_t GpuQueue::size()const{return q_.size();}
