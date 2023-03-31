// clang-format off
#include "rzxpch.h"
// clang-format on
#include "RZSoundEngine.h"


namespace Razix {
    namespace Audio {

        void RZSoundEngine::StartUp()
        {
            RAZIX_CORE_INFO("[Sound Engine] Starting Up Sound Engine");
            RAZIX_CORE_INFO("[Sound Engine] Backend: OpenAL");
        }

        void RZSoundEngine::ShutDown()
        {
            RAZIX_CORE_INFO("[Sound Engine] Shutting Down Sound Engine");
        }

        void RZSoundEngine::renderAudio()
        {
        }

    }    // namespace Audio
}    // namespace Razix