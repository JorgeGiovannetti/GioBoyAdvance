#include <core/log.h>

#include <spdlog/sinks/stdout_color_sinks.h>

namespace platform::core
{
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
    std::shared_ptr<spdlog::logger> Log::s_GBALogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_ClientLogger = spdlog::stdout_color_mt("EMULATOR");
        s_ClientLogger->set_level(spdlog::level::trace);

        s_GBALogger = spdlog::stdout_color_mt("GBA");
        s_GBALogger->set_level(spdlog::level::trace);        
    }

}