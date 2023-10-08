#include "vd_instance.h"

#include <iostream>
#include <vector>

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.hpp>

namespace vd
{
	vd_instance::vd_instance()
	{
		create_instance(1, "Vulkan Demo");
	}
		
	vd_instance::~vd_instance()
	{
	}
	
	void vd_instance::create_instance(
		bool p_debug,
		const char* p_application_name
	)
	{
		uint32_t version{0};

		if (p_debug) {
			std::cout << "Making an Instance.. \n";
			vkEnumerateInstanceVersion(&version);
			std::cout << "System can supoprt vulkan Variant: "
				<<  VK_API_VERSION_VARIANT(version)
				<< ", Major: " << VK_API_VERSION_MAJOR(version)
				<< ", Minor: " << VK_API_VERSION_MINOR(version)
				<< ", Patch: " << VK_API_VERSION_PATCH(version) << "\n";
		}

		/**
		 * Bitwise remove the lower 12 bytes that hold the patch version for compatibility
		*/
		version &= ~(0XFFFU);

		/**
		 * or drop down to an earlier version to ensure compatibility with more devices
		 * VK_MAKE_API_VERSION(variant, major, minor, patch)
		*/
		version = VK_MAKE_API_VERSION(0,1,0,0);

		/**
		 * Declare Application Info
		*/

		vk::ApplicationInfo appInfo = vk::ApplicationInfo(
			p_application_name,
			version,
			"doing it again",
			version,
			version
		);

		/**
		 * Vulkan needs to be transparent as possible, we need to query the extensions that glfw needs
		 * in order to interface with vulkan
		*/
		uint32_t glfw_extension_count = 0;
		const char** glfw_extensions;
		glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);
		
		std::vector<const char*> extensions(glfw_extensions, glfw_extensions +  glfw_extension_count);
		
		if (p_debug) {
			std::cout << "extensions to be requested: \n";

			for (const char* i_extension_name : extensions)
			{
				std::cout << "\t\"" << i_extension_name << "\"\n";
			}
		}
		
	}

} // namespace vd

