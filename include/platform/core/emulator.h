#pragma once

#include "window.h"
#include "graphics/renderer.h"

namespace platform::core
{
    class Emulator
    {
    public:
        static Emulator &Instance();
        ~Emulator() {}
        void Run();
        inline void Quit() { mIsRunning = false; }
        inline Window& GetWindow() { return mWindow; }
        inline platform::graphics::Renderer& GetRenderer() { return mRenderer; }

    private:
        bool Initialize();
        void Shutdown();
        void GetInfo();

        Window mWindow;
        bool mIsRunning;

        platform::graphics::Renderer mRenderer;

        // Singleton
        Emulator();
        static Emulator *mInstance;
    };
}