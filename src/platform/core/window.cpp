#include <core/emulator.h>
#include <core/log.h>
#include <core/window.h>

#include <imgui/imgui.h>
#include <SDL2/SDL.h>
#include <glad/glad.h>

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
        mWindow = SDL_CreateWindow("GioBoyAdvance", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 320, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
        if (!mWindow)
        {
            CLIENT_LOG_ERROR("Error creating window: {}", SDL_GetError());
            return false;
        }

#ifdef GIO_PLATFORM_MAC
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
#endif
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        SDL_SetWindowMinimumSize(mWindow, 240, 160);

        mGLContext = SDL_GL_CreateContext(mWindow);
        if (mGLContext == nullptr)
        {
            CLIENT_LOG_ERROR("Error creating window: {}", SDL_GetError());
            return false;
        }

        gladLoadGLLoader(SDL_GL_GetProcAddress);

        mMenuBar.Create();

        return true;
    }

    void Window::Shutdown()
    {
        SDL_DestroyWindow(mWindow);
        SDL_GL_DeleteContext(mGLContext);
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

    void Window::BeginRender()
    {
        auto &renderer = Emulator::Instance().GetRenderer();
        renderer.Clear();
        mMenuBar.BeginRender();
    }

    void Window::EndRender()
    {
        mMenuBar.Show();
        mMenuBar.EndRender();
        SDL_GL_SwapWindow(mWindow);
    }

    void Window::SetTitle(const std::string& title)
    {
        SDL_SetWindowTitle(mWindow, title.c_str());
    }

    void Window::GetSize(int &w, int &h)
    {
        SDL_GetWindowSize(mWindow, &w, &h);
    }
}