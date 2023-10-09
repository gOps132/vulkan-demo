#include "Log.h"

namespace vd {
std::shared_ptr<spdlog::logger> Log::s_client_logger;

void Log::init(const std::string &p_logging_name)
{
	spdlog::set_pattern("%^[%T] %n: %v%$");

	s_client_logger = spdlog::stdout_color_mt(p_logging_name);
	s_client_logger->set_level(spdlog::level::trace);
}
} // namespace vd