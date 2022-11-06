cmake_minimum_required(VERSION 3.25)
project(vulkan-demo
    DESCRIPTION "Just me learning some vulkan"
)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)

find_package(Vulkan REQUIRED COMPONENTS glslc)

set(VULKAN_DEMO_SOURCES 
    src/main.cpp
	src/v_demo_window.cpp
	src/application.cpp
)

set(SHADER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/shaders)
# set(SHADER_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/shaders)
set(SHADER_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/shaders)

# file(GLOB SHADERS 
# 	${SHADER_SOURCE_DIR}/*.vert
# 	${SHADER_SOURCE_DIR}/*.frag
# 	${SHADER_SOURCE_DIR}/*.comp
# 	${SHADER_SOURCE_DIR}/*.geom
# 	${SHADER_SOURCE_DIR}/*.tesc
# 	${SHADER_SOURCE_DIR}/*.tese
# 	${SHADER_SOURCE_DIR}/*.mesh
# 	${SHADER_SOURCE_DIR}/*.task
# 	${SHADER_SOURCE_DIR}/*.rgen
# 	${SHADER_SOURCE_DIR}/*.rchit
# 	${SHADER_SOURCE_DIR}/*.rmiss
# )

# --------------------------------------
# COMPILE SHADERS INTO SPIR-V
# --------------------------------------
message("location at: ${Vulkan_GLSLC_EXECUTABLE}")	
message("location at: ${Vulkan_GLSLANG_VALIDATOR_EXECUTABLE}")

message("SHADERS: ${SHADERS}")

# CMake function for simple compile of shader.xxx to xxx.spv
# this works well, but:
# -- doesn't force shader compile when shader.xxx source changes
# -- compiles all shaders every time project rebuilds.
function(compile_shader NAME)
	message("COMPILE_SHADER RUNNING: ${NAME}")
	message("COMMAND: ${Vulkan_GLSLC_EXECUTABLE} ${SHADER_SOURCE_DIR}/${NAME} -o ${SHADER_BINARY_DIR}/${NAME}.spv")
    # create a variable of all compiled shader file names, for add_custom_target
    set(SPV_FILES ${SPV_FILES} ${SHADER_BINARY_DIR}/${NAME}.spv PARENT_SCOPE)

    add_custom_command(TARGET vulkan-demo PRE_BUILD
            COMMAND ${Vulkan_GLSLC_EXECUTABLE} ${SHADER_SOURCE_DIR}/${NAME} -o ${SHADER_BINARY_DIR}/${NAME}.spv
            WORKING_DIRECTORY ${SHADER_SOURCE_DIR}
            COMMENT "Compiling shader.${NAME} to ${NAME}.spv")
endfunction()

# --------------------------------------
# BUILD VULKAN DEMO
# --------------------------------------
add_executable(vulkan-demo ${VULKAN_DEMO_SOURCES})

compile_shader("example_shader.vert")
compile_shader("example_shader.frag")

target_include_directories(vulkan-demo PUBLIC ${Vulkan_INCLUDE_DIRS})

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}/${CMAKE_BUILD_TYPE}")

set_target_properties(vulkan-demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY    ${OUTPUT_DIR}
)

target_include_directories(vulkan-demo 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(vulkan-demo
    PRIVATE     glfw
    PRIVATE     glm
    PRIVATE     Vulkan::Vulkan
)