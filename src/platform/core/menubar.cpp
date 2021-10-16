#include <core/menubar.h>
#include <core/emulator.h>
#include <core/log.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl3.h>

namespace platform::core
{
    void MenuBar::Create()
    {
        IMGUI_CHECKVERSION();

        ImGui::CreateContext();

        Window &window = Emulator::Instance().GetWindow();
        ImGui_ImplSDL2_InitForOpenGL(window.GetSDLWindow(), window.GetGLContext());
        ImGui_ImplOpenGL3_Init();
    }

    void MenuBar::Shutdown()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
    }

    void MenuBar::HandleSDLEvent(SDL_Event &e)
    {
        ImGui_ImplSDL2_ProcessEvent(&e);
    }

    void MenuBar::BeginRender()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(Emulator::Instance().GetWindow().GetSDLWindow());
        ImGui::NewFrame();
    }

    void MenuBar::EndRender()
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void MenuBar::Show()
    {
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                ShowMenuFile();
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Options"))
            {
                ShowMenuOptions();
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
    }

    void MenuBar::ShowMenuFile()
    {
        if (ImGui::MenuItem("Open", "Ctrl+O"))
        {
            Emulator::Instance().LoadROM();
        }
        if (ImGui::BeginMenu("Open Recent"))
        {
            auto &recentRoms = Emulator::Instance().GetRecentROMs();

            for (auto &rom : recentRoms)
            {
                if (ImGui::MenuItem(rom.c_str()))
                {
                    Emulator::Instance().LoadROM(rom);
                }
            }
            ImGui::EndMenu();
        }

        ImGui::Separator();

        if (ImGui::MenuItem("Close", "Ctrl+W"))
        {
            Emulator::Instance().CloseROM();
        }

        if (ImGui::MenuItem("Quit", "Alt+F4"))
        {
            Emulator::Instance().Quit();
        }
    }

    void MenuBar::ShowMenuOptions()
    {
        ImGui::MenuItem("Configure...");
    }
}