#ifndef LOG_H
#define LOG_H

#include <string>

namespace DarknessEngine{
    class Log{
    public:
        static void trace(const std::string& msg, const std::string& sender);
        static void info(const std::string& msg, const std::string& sender);
        static void warn(const std::string& msg, const std::string& sender);
        static void error(const std::string& msg, const std::string& sender);
    };
}

#ifdef DE_LOG_ENABLED

#define LOG_TRACE(msg) DarknessEngine::Log::trace(msg, "Client")
#define LOG_INFO(msg) DarknessEngine::Log::info(msg, "Client")
#define LOG_WARN(msg) DarknessEngine::Log::warn(msg, "Client")
#define LOG_ERROR(msg) DarknessEngine::Log::error(msg, "Client")
#define LOG_CORE_TRACE(msg) DarknessEngine::Log::trace(msg, "Core")
#define LOG_CORE_INFO(msg) DarknessEngine::Log::info(msg, "Core")
#define LOG_CORE_WARN(msg) DarknessEngine::Log::warn(msg, "Core")
#define LOG_CORE_ERROR(msg) DarknessEngine::Log::error(msg, "Core")

#else

#define LOG_TRACE(msg)
#define LOG_INFO(msg)
#define LOG_WARN(msg)
#define LOG_ERROR(msg)
#define LOG_CORE_TRACE(msg)
#define LOG_CORE_INFO(msg)
#define LOG_CORE_WARN(msg)
#define LOG_CORE_ERROR(msg)

#endif

#endif