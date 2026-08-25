#include "debugger.hpp"
void Debugger::log(const std::string&s){logs_.push_back(s);}
std::size_t Debugger::count()const{return logs_.size();}
