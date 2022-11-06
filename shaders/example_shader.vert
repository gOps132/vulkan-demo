// glsl version 4.5
#version 450

// hardcoded vertices
vec2 positions[3] = vec2[](
	vec2(0.0, -0.5),
	vec2(0.5, 0.5),
	vec2(-0.5, 0.5)
);

void main()
{
	// once per each vertex we have
	
	// 4d vector that match to our output frame buffer image
	// y coodindate is flipped

	// gl_Position is the built in output variable
	// gl_VertexIndex contains the index for the current vertex each time the main function is run
	// z == 0.0 - 1.0
	// turn into a normalized device coordinate, divides a whole vector list by it's last component
	gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
}