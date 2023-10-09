#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "vd_window.h"
#include "vd_instance.h"
#include "vd_pipeline.h"

namespace vd {
class Application {
public:
	Application();
	void run();

	vd_window m_application_window;
	vd_pipeline m_vd_pipeline{	"shaders/example_shader.vert.spv",
								"shaders/example_shader.frag.spv" };

	static vk::Instance s_instance;
};

} // namespace vd

#endif // __APPLICATION_H__