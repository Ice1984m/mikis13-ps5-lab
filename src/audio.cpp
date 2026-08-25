#include "audio.hpp"
void Audio::submit(std::size_t f){frames_+=f;}
std::size_t Audio::submitted()const{return frames_;}
