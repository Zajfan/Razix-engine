// clang-format off
#include "rzxpch.h"
// clang-format on
#include "RZSwapchain.h"

#include "Razix/Gfx/RHI/API/RZGraphicsContext.h"

#ifdef RAZIX_RENDER_API_OPENGL
    #include "Razix/Platform/API/OpenGL/OpenGLSwapchain.h"
#endif

#ifdef RAZIX_RENDER_API_VULKAN
    #include "Razix/Platform/API/Vulkan/VKContext.h"
    #include "Razix/Platform/API/Vulkan/VKSwapchain.h"
#endif

#ifdef RAZIX_RENDER_API_DIRECTX11
    #include "Razix/Platform/API/DirectX11/DX11Context.h"
    #include "Razix/Platform/API/DirectX11/DX11Swapchain.h"
#endif

#ifdef RAZIX_RENDER_API_DIRECTX12
    #include "Razix/Platform/API/DirectX12/DX12Context.h"
    #include "Razix/Platform/API/DirectX12/DX12Swapchain.h"
#endif

namespace Razix {
    namespace Gfx {

        RZSwapchain* RZSwapchain::Create(u32 width, u32 height)
        {
            RAZIX_PROFILE_FUNCTIONC(RZ_PROFILE_COLOR_GRAPHICS);

            switch (Gfx::RZGraphicsContext::GetRenderAPI()) {
#ifdef RAZIX_RENDER_API_OPENGL
                case Razix::Gfx::RenderAPI::OPENGL: return new OpenGLSwapchain(width, height); break;
#endif

#ifdef RAZIX_RENDER_API_VULKAN
                case Razix::Gfx::RenderAPI::VULKAN: return static_cast<RZSwapchain*>(VKContext::Get()->getSwapchain().get());    //return new VKSwapchain(width, height); break;
#endif
#ifdef RAZIX_RENDER_API_DIRECTX11
                case Razix::Gfx::RenderAPI::D3D11: return DX11Context::Get()->getSwapchain(); break;
#endif
#ifdef RAZIX_RENDER_API_DIRECTX12
                case Razix::Gfx::RenderAPI::D3D12: return static_cast<RZSwapchain*>(DX12Context::Get()->getSwapchain().get());
#endif
                case Razix::Gfx::RenderAPI::GXM:
                case Razix::Gfx::RenderAPI::GCM:
                default: return nullptr; break;
            }
        }

    }    // namespace Gfx
}    // namespace Razix