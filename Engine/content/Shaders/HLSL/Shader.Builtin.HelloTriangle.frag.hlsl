/*
 * Razix Engine GLSL Vertex Shader File
 * Default Vertex Shader that can be used for rendering basic geometry with vertex colors and use a texture as well
 */
//------------------------------------------------------------------------------
#include "../ShaderCommon/ShaderInclude.Builtin.ShaderLangCommon.h"
//------------------------------------------------------------------------------
struct PSIn
{
    float4 Color      : COLOR0;
};
 //------------------------------------------------------------------------------
float4 PS_MAIN(PSIn psIn) : SV_TARGET
{
    return psIn.Color;
}