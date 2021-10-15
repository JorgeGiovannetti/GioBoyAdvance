#pragma once

typedef union SDL_Event SDL_Event;
namespace platform::core
{
    class MenuBar
    {
    public:
        MenuBar() {}
        ~MenuBar() {}

        void Create();
        void Shutdown();

        void HandleSDLEvent(SDL_Event &e);

        void BeginRender();
        void EndRender();
    };
}