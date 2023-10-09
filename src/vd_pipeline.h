#ifndef __VD_PIPELINE_H__
#define __VD_PIPELINE_H__

#include <string>
#include <vector>

namespace vd {
class vd_pipeline {
public:
	vd_pipeline() {}
	vd_pipeline(const std::string &p_vert_filepath,
				const std::string &p_frag_filepath);

private:
	static std::vector<char> read_file(const std::string &p_filepath);
	void create_graphics_pipeline(const std::string &p_vert_filepath,
								  const std::string &p_frag_filepath);
};

} // namespace vd

#endif // __VD_PIPELINE_H__