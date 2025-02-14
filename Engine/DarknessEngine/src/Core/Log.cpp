#include "pch.h"

#include "Core/Log.h"

namespace DarknessEngine{
    void Log::trace(const std::string& msg, const std::string& sender){
        std::cout << "\033[0m" << "[" << sender << "]: " << msg << "\033[0m\n";
    }

    void Log::info(const std::string& msg, const std::string& sender){
        std::cout << "\033[0;32m" << "[" << sender << "]: " << msg << "\033[0m\n";
    }

    void Log::warn(const std::string& msg, const std::string& sender){
        std::cout << "\033[0;33m" << "[" << sender << "]: " << msg << "\033[0m\n";
    }

    void Log::error(const std::string& msg, const std::string& sender){
        std::cout << "\033[0;31m" << "[" << sender << "]: " << msg << "\033[0m\n";
    }
}