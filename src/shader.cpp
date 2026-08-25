#include "shader.hpp"

ShaderTranslation translateTestShader(
    const std::string& source
)
{
    if (source.empty())
    {
        return {
            false,
            "none",
            "empty shader"
        };
    }

    return {
        true,
        "SPIR-V research target",
        "translation stub"
    };
}
