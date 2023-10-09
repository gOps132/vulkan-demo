#ifndef __LOG_H__
#define __LOG_H__

/*
 * Taken from zyklon code
 */

#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace vd {
class Log {
public:
	static void init(const std::string &p_logging_name);

	inline static std::shared_ptr<spdlog::logger> &get_client_logger()
	{
		return s_client_logger;
	}

private:
	static std::shared_ptr<spdlog::logger> s_client_logger;
};

} // namespace vd

#define VD_TRACE(...) ::vd::Log::get_client_logger()->trace(__VA_ARGS__)
#define VD_INFO(...) ::vd::Log::get_client_logger()->info(__VA_ARGS__)
#define VD_WARN(...) ::vd::Log::get_client_logger()->warn(__VA_ARGS__)
#define VD_ERROR(...) ::vd::Log::get_client_logger()->error(__VA_ARGS__)
#define VD_CRITICAL(...)                                                   \
	::vd::Log::get_client_logger()->critical(__VA_ARGS__)

#endif // __LOG_H__