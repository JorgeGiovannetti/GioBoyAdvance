#pragma once

#include "window.h"

namespace platform::core
{
    class Emulator
    {
    public:
        static Emulator &Instance();
        ~Emulator() {}
        void Run();
        inline void Quit() { mIsRunning = false; }

    private:
        bool Initialize();
        void Shutdown();
        void GetInfo();

        Window mWindow;
        bool mIsRunning;

        // Singleton
        Emulator();
        static Emulator *mInstance;
    };
}