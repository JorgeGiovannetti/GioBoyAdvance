#include <SDL2/SDL.h>

#include <core/emulator.h>
#include <core/log.h>
#include <core/window.h>

namespace platform::core
{
    Emulator::Emulator() : mIsRunning(false)
    {
        platform::core::Log::Init();
        GetInfo();
    }

    Emulator &Emulator::Instance()
    {
        static Emulator mInstance;
        return mInstance;
    }

    void Emulator::Run()
    {
        if (Initialize())
        {
            while (mIsRunning)
            {
                mWindow.PumpEvents();
                mWindow.BeginRender();
                mWindow.EndRender();
            }

            Shutdown();
        }
    }

    bool Emulator::Initialize()
    {
        bool ret = false;

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            platform::core::Log::GetClientLogger()->critical("Error initializing SDL2: {}", SDL_GetError());
        }
        else
        {
            SDL_version version;
            SDL_VERSION(&version);
            CLIENT_LOG_WARN("SDL {}.{}.{}", (int32_t)version.major, (int32_t)version.minor, (int32_t)version.patch);
            CLIENT_LOG_WARN("SDL_GLContext version {}.{}", SDL_GL_CONTEXT_MAJOR_VERSION, SDL_GL_CONTEXT_MINOR_VERSION);

            CLIENT_LOG_TRACE("Initializing...");

            if (mWindow.Create())
            {
                mRenderer.Initialize();

                ret = true;
                mIsRunning = true;
            }
        }

        if (ret)
        {
            CLIENT_LOG_INFO("Hello world, GioBoyAdvance!");
        }
        else
        {
            CLIENT_LOG_ERROR("Initialization failed");
            Shutdown();
        }

        return ret;
    }

    void Emulator::Shutdown()
    {
        CLIENT_LOG_WARN("Shutting down...");
        mIsRunning = false;

        mRenderer.Shutdown();

        mWindow.Shutdown();
        SDL_Quit();
    }

    void Emulator::GetInfo()
    {
#ifdef GIO_CONFIG_DEBUG
        CLIENT_LOG_WARN("Configuration: DEBUG");
#endif
#ifdef GIO_CONFIG_RELEASE
        CLIENT_LOG_WARN("Configuration: RELEASE");
#endif
#ifdef GIO_PLATFORM_WINDOWS
        CLIENT_LOG_WARN("Platform: Windows");
#endif
#ifdef GIO_PLATFORM_MAC
        CLIENT_LOG_WARN("Platform: Mac");
#endif
#ifdef GIO_PLATFORM_LINUX
        CLIENT_LOG_WARN("Platform: Linux");
#endif
    }
}