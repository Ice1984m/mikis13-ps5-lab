#pragma once

#include <string>

struct ShaderTranslation
{
    bool accepted = false;
    std::string target;
    std::string note;
};

ShaderTranslation translateTestShader(
    const std::string& source
);
