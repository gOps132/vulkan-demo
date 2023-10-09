#include "vd_instance.h"

#include <iostream>
#include <vector>

#include "Log.h"
namespace vd
{
	vk::Instance create_instance(
		bool p_debug,
		const char* p_application_name
	)
	{
		uint32_t version{0};

		if (p_debug) {
			VD_INFO("Making Instance...");
			vkEnumerateInstanceVersion(&version);
			VD_INFO("System can supoprt vulkan Variant: {0}, Major: {1}, Minor: {2}, Patch: {3}",
				VK_API_VERSION_VARIANT(version),
				VK_API_VERSION_MAJOR(version),
				VK_API_VERSION_MINOR(version),
				VK_API_VERSION_PATCH(version));
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
		
		/** 
		 *	now that we got the info that the application needs we need to create info
		 *	VULKAN_HPP_CONSTEXPR InstanceCreateInfo( VULKAN_HPP_NAMESPACE::InstanceCreateFlags     flags_                 = {},
                const VULKAN_HPP_NAMESPACE::ApplicationInfo * pApplicationInfo_      = {},
                uint32_t                                      enabledLayerCount_     = {},
                const char * const *                          ppEnabledLayerNames_   = {},
                uint32_t                                      enabledExtensionCount_ = {},
                const char * const * ppEnabledExtensionNames_ = {} ) VULKAN_HPP_NOEXCEPT
		*/
		vk::InstanceCreateInfo create_info = vk::InstanceCreateInfo(
			vk::InstanceCreateFlags(),
			&appInfo,
			0, nullptr, // enabled layers
			static_cast<uint32_t>(extensions.size()),
			extensions.data() // enabled extensions
		);

		/**
		 *     createInstance( const InstanceCreateInfo &          	createInfo,
		 *			Optional<const AllocationCallbacks> 			allocator,
		 *			Dispatch const &                    			d = ::vk::getDispatchedLoaderStatic()
		 *		)
		*/
		try {
			return vk::createInstance(create_info);
		}
		catch (vk::SystemError err) {
			if (p_debug) {
				std::cout << "Failed to create Instance \n";
			}
			return nullptr;
		}
		return nullptr;
	}

} // namespace vd