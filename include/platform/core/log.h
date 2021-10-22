#pragma once

#include <spdlog/spdlog.h>

namespace platform::core
{
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetGBALogger() { return s_GBALogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
        static std::shared_ptr<spdlog::logger> s_GBALogger;
    };
}

// Client log macros
#define CLIENT_LOG_TRACE(...) ::platform::core::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CLIENT_LOG_INFO(...) ::platform::core::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_LOG_WARN(...) ::platform::core::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_LOG_ERROR(...) ::platform::core::Log::GetClientLogger()->error(__VA_ARGS__)

// GBA log macros
#define GBA_LOG_TRACE(...) ::platform::core::Log::GetGBALogger()->trace(__VA_ARGS__)
#define GBA_LOG_INFO(...) ::platform::core::Log::GetGBALogger()->info(__VA_ARGS__)
#define GBA_LOG_WARN(...) ::platform::core::Log::GetGBALogger()->warn(__VA_ARGS__)
#define GBA_LOG_ERROR(...) ::platform::core::Log::GetGBALogger()->error(__VA_ARGS__)
