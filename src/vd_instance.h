#ifndef __VD_INSTANCE_H__
#define __VD_INSTANCE_H__


#include <GLFW/glfw3.h>
#include <vulkan/vulkan.hpp>

namespace vd
{

	vk::Instance create_instance(
		bool p_debug,
		const char* p_application_name
	);
		
} // namespace vd


#endif // __VD_INSTANCE_H__