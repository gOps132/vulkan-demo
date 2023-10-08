#ifndef __V_DEMO_WINDOW_H__
#define __V_DEMO_WINDOW_H__

#include <GLFW/glfw3.h>

#include <vulkan/vulkan.hpp>

#include <string>

namespace vd {

typedef struct window_default_props {
public:
	uint32_t m_width = 1080;
	uint32_t m_height = 720;
	std::string m_window_name = "Vulkan Demo";
} window_default_props;

class vd_window {
private:
	GLFWwindow *m_window;
	window_default_props m_window_props;
	void init_window();

public:
	vd_window();
	vd_window(uint32_t p_width, uint32_t p_height, std::string p_window_name);

	// no copy
	vd_window(const vd_window &) = delete;
	vd_window &operator=(const vd_window) = delete;

	~vd_window();

	bool window_should_close();
};

} // namespace vd

#endif // __V_DEMO_WINDOW_H__