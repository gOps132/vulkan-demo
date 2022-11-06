#include "application.h"

namespace vd {
void Application::run()
{
	while (!m_application_window.window_should_close()) {
		glfwPollEvents();
	}
}
} // namespace vd
