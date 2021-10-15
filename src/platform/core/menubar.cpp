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
}