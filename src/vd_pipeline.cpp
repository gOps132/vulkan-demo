#include "vd_pipeline.h"

#include <fstream>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

namespace vd {
vd_pipeline::vd_pipeline(const std::string &p_vert_filepath,
						 const std::string &p_frag_filepath)
{
	create_graphics_pipeline(p_vert_filepath, p_frag_filepath);
}

std::vector<char> vd_pipeline::read_file(const std::string &p_filepath)
{

	std::ifstream file(p_filepath, std::ios::ate | std::ios::binary);

	if (!file.is_open()) {
		throw std::runtime_error("Fail to open file: " + p_filepath);
	}

	size_t file_size = static_cast<size_t>(file.tellg());
	std::vector<char> buffer(file_size);

	// read data
	file.seekg(0);
	file.read(buffer.data(), file_size);

	file.close();

	return buffer;
}

void vd_pipeline::create_graphics_pipeline(const std::string &p_vert_filepath,
										   const std::string &p_frag_filepath)
{
	auto vert_code = read_file(p_vert_filepath);
	auto frag_code = read_file(p_frag_filepath);

	std::cout << "Vertex Shader Size: " << vert_code.size() << "\n";
	std::cout << "Fragment Shader Size: " << frag_code.size() << "\n";
};

} // namespace vd
