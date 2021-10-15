#include <core/log.h>

#include <glad/glad.h>
#include <graphics/renderer.h>

namespace platform::graphics
{
    void Renderer::Initialize()
    {
        CLIENT_LOG_INFO("OpenGL Info:\n Vendor:\t{}\n Renderer:\t{}\n Version:\t{}",
                        (const char*)glGetString(GL_VENDOR),
                        (const char*)glGetString(GL_RENDERER),
                        (const char*)glGetString(GL_VERSION));

        // Initialize OpenGL

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void Renderer::Shutdown()
    {
    }

    void Renderer::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::SetClearColor(float r, float g, float b, float a)
    {
        glClearColor(0, 0, 0, 1);
    }
}