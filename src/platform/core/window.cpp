#include <iostream>

#include <SDL2/SDL.h>
#include <core/window.h>
#include <core/emulator.h>

namespace platform::core
{
    Window::Window() : mWindow(nullptr) {}
    Window::~Window()
    {
        if (mWindow)
        {
            Shutdown();
        }
    }

    bool Window::Create()
    {
        mWindow = SDL_CreateWindow("GioBoyAdvance", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 320, 0);
        if (!mWindow)
        {
            std::cout << "Error creating window: " << SDL_GetError() << std::endl;
            return false;
        }

        return true;
    }

    void Window::Shutdown()
    {
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;
    }

    void Window::PumpEvents()
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_QUIT:
                Emulator::Instance().Quit();
                break;
            default:
                break;
            }
        }
    }
}