#version 450

// unlike the vertex shader there isn't a built in output variable so we declare
// (layout qualifier) takes the location value
// fragment shader is able to output to multiple different locations
// declare as output using the out qualifier
// declare type
// declare name
layout (location = 0) out vec4 out_color;

// the fragment shader runs on a per fragment basis, which are determined  by what pixels our geometry
// mostly contains on our rasterization stage

void main()
{
	// RGBA
	out_color = vec4(1.0, 0.0, 0.0, 1.0);
}