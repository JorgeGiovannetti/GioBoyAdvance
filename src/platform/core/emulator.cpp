#include <iostream>

#include <SDL2/SDL.h>

#include <core/window.h>
#include <core/emulator.h>


namespace platform::core
{
    Emulator &Emulator::Instance()
    {
        static Emulator mInstance;
        return mInstance;
    }

    bool Emulator::Initialize()
    {
        bool ret = true;

        std::cout << "Hello world, GioBoyAdvance!" << std::endl;

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            std::cout << "Error initializing SDL2: " << SDL_GetError() << std::endl;
        }
        else
        {
            SDL_version version;
            SDL_VERSION(&version);
            std::cout << "SDL " << (int32_t)version.major << "." << (int32_t)version.minor << "." << (int32_t)version.patch << std::endl;

            if (!mWindow.Create())
            {
                ret = false;
            }
        }

        return ret;
    }

    void Emulator::Shutdown()
    {
        mWindow.Shutdown();
        SDL_Quit();
    }

    void Emulator::GetInfo()
    {
#ifdef GIO_CONFIG_DEBUG
        std::cout << "Configuration: DEBUG" << std::endl;
#endif
#ifdef GIO_CONFIG_RELEASE
        std::cout << "Configuration: RELEASE" << std::endl;
#endif
#ifdef GIO_PLATFORM_WINDOWS
        std::cout << "Platform: Windows" << std::endl;
#endif
#ifdef GIO_PLATFORM_MAC
        std::cout << "Platform: Mac" << std::endl;
#endif
#ifdef GIO_PLATFORM_LINUX
        std::cout << "Platform: Linux" << std::endl;
#endif
    }
}