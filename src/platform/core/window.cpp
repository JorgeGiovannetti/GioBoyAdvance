#include <iostream>

#include <SDL2/SDL.h>
#include <core/window.h>

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
}