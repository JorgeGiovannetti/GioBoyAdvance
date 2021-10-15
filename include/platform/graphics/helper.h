#pragma once

#include <core/log.h>

#include <glad/glad.h>
#include <string>

namespace platform::graphics
{
    void CheckGLError()
    {
        GLenum error = glGetError();
        while (error != GL_NO_ERROR)
        {
            std::string errorstr;
            switch (error)
            {
            case GL_INVALID_OPERATION:
                errorstr = "GL_INVALID_OPERATION";
                break;
            case GL_INVALID_ENUM:
                errorstr = "GL_INVALID_ENUM";
                break;
            case GL_INVALID_VALUE:
                errorstr = "GL_INVALID_VALUE";
                break;
            case GL_OUT_OF_MEMORY:
                errorstr = "GL_OUT_OF_MEMORY";
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                errorstr = "GL_INVALID_FRAMEBUFFER_OPERATION";
                break;
            default:
                errorstr = std::to_string(error);
                break;
            }

            CLIENT_LOG_ERROR("OpenGL Error: {}", errorstr.c_str());
            error = glGetError();
        }
    }
}

#ifndef GIO_CONFIG_RELEASE
#define CLIENT_CHECK_GL_ERROR platform::graphics::CheckGLError();
#else
#define CLIENT_CHECK_GL_ERROR (void)0
#endif