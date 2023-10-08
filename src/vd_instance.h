#ifndef __VD_INSTANCE_H__
#define __VD_INSTANCE_H__

namespace vd
{
	class vd_instance
	{
	public:
		vd_instance();
		~vd_instance();

		void create_instance(bool p_debug, const char* p_application_name);
	};

} // namespace vd


#endif // __VD_INSTANCE_H__