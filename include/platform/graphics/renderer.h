#pragma once

namespace platform::graphics
{
    class Renderer
    {
        public:
            Renderer(){}
            ~Renderer(){}

            void Initialize();
            void Shutdown();

            void Clear();
            void SetClearColor(float r, float g, float b, float a);
    };
}