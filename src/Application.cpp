#include "application.h"
#include "Log.h"
#include "vd_instance.h"

#include <iostream>
namespace vd {

vk::Instance Application::s_instance = nullptr;

Application::Application() 
{
	std::cout << "creating application \n";
	s_instance = create_instance(true, "Vulkan Demo");	
}

void Application::run()
{
	while (!m_application_window.window_should_close()) {
		glfwPollEvents();
	}
}

} // namespace vd
