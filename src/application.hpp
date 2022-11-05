#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "v_demo_window.hpp"

namespace vd {
class Application {
public:
	void run();

private:
	v_demo_window m_application_window;
};

} // namespace vd

#endif // __APPLICATION_H__