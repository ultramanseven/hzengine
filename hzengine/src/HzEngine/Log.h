#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"

namespace HzEngine {
	class HAZEL_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core log macros
#define HZ_CORE_TRACE(...)  ::HzEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)  ::HzEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)  ::HzEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)  ::HzEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)  ::HzEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define HZ_TRACE(...)  ::HzEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)  ::HzEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)  ::HzEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)  ::HzEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)  ::HzEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

