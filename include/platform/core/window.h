#pragma once

struct SDL_Window;
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

        private:
            SDL_Window* mWindow;
    };
}