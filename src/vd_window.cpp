#include "vd_window.h"

namespace vd {
vd_window::vd_window() { init_window(); }
vd_window::vd_window(uint32_t p_width, uint32_t p_height,
					 std::string p_window_name)
{
	m_window_props.m_width = p_width;
	m_window_props.m_height = p_height;
	m_window_props.m_window_name = p_window_name;

	init_window();
}

vd_window::~vd_window()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

bool vd_window::window_should_close()
{
	return glfwWindowShouldClose(m_window);
}

void vd_window::init_window()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_window = glfwCreateWindow(m_window_props.m_width, m_window_props.m_height,
								m_window_props.m_window_name.c_str(), nullptr,
								nullptr);
}

} // namespace vd