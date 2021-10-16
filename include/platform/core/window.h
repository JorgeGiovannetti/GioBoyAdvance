#pragma once

#include <core/menubar.h>

#include <string>

struct SDL_Window;
using SDL_GLContext = void*;
namespace platform::core
{
    class Window
    {
        public:
            Window();
            ~Window();

            bool Create();
            void Shutdown();
            
            void PumpEvents();

            void SetTitle(const std::string& title);
            void GetSize(int& w, int& h);

            SDL_Window* GetSDLWindow() { return mWindow; }
            SDL_GLContext GetGLContext() { return mGLContext; }

            void BeginRender();
            void EndRender();

        private:
            SDL_Window* mWindow;
            SDL_GLContext mGLContext;
            MenuBar mMenuBar;
    };
}