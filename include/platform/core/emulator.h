#pragma once

#include "window.h"
#include "graphics/renderer.h"

#include <utils/ROMHistory.h>

namespace platform::core
{
    class Emulator
    {
    public:
        static Emulator &Instance();
        ~Emulator() {}
        void Run();
        inline Window &GetWindow() { return mWindow; }
        inline platform::graphics::Renderer &GetRenderer() { return mRenderer; }

        inline void Quit() { mIsRunning = false; }
        void CloseROM();
        void LoadROMFile();
        void LoadROMFile(const std::string &filepath);
        platform::utils::ROMHistory &GetRecentROMs() { return mRecentROMs; }

    private:
        bool Initialize();
        void Shutdown();
        void GetInfo();
        void LoadROM(const std::string &filepath);

        Window mWindow;
        bool mIsRunning;
        platform::utils::ROMHistory mRecentROMs;

        platform::graphics::Renderer mRenderer;

        // Singleton
        Emulator();
        static Emulator *mInstance;
    };
}