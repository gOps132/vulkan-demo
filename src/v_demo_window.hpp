#ifndef __V_DEMO_WINDOW_H__
#define __V_DEMO_WINDOW_H__

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace vd {

typedef struct window_default_props {
public:
	uint32_t m_width = 1080;
	uint32_t m_height = 720;
	std::string m_window_name = "Vulkan Demo";
} window_default_props;

class v_demo_window {
private:
	GLFWwindow *m_window;
	window_default_props m_window_props;
	void init_window();

public:
	v_demo_window();
	v_demo_window(uint32_t p_width, uint32_t p_height,
				  std::string p_window_name);

	// no copy
	v_demo_window(const v_demo_window &) = delete;
	v_demo_window &operator=(const v_demo_window) = delete;

	~v_demo_window();

	bool window_should_close();
};

} // namespace vd

#endif // __V_DEMO_WINDOW_H__