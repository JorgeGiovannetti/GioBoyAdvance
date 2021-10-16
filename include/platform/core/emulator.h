#pragma once

#include "window.h"
#include "graphics/renderer.h"

#include <vector>

namespace platform::core
{
    class Emulator
    {
    public:
        static Emulator &Instance();
        ~Emulator() {}
        void Run();
        inline Window& GetWindow() { return mWindow; }
        inline platform::graphics::Renderer& GetRenderer() { return mRenderer; }

        inline void Quit() { mIsRunning = false; }
        void CloseROM();
        void LoadROMFile();
        void LoadROMFile(const std::string& filepath);
        std::vector<std::string>& GetRecentROMs() { return recentROMs; }

    private:
        bool Initialize();
        void Shutdown();
        void GetInfo();
        void LoadROM(const std::string& filepath);

        Window mWindow;
        bool mIsRunning;
        std::vector<std::string> recentROMs { "Game1.gba", "Game.gbc"};

        platform::graphics::Renderer mRenderer;

        // Singleton
        Emulator();
        static Emulator *mInstance;
    };
}