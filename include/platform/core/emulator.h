#pragma once

#include "window.h"

namespace platform::core
{
    class Emulator
    {
    public:
        static Emulator &Instance();
        Emulator();
        ~Emulator() {}

        bool Initialize();
        void Shutdown();

    private:
        void GetInfo();

        Window mWindow;

        // Singleton
        static Emulator *mInstance;
    };
}