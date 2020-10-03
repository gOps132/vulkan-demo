cmake_minimum_required(VERSION 3.14)
project(vulkan-demo
    DESCRIPTION "Just me learning some vulkan"
)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)

set(SOURCES 
    src/samp.cpp
)

add_executable(vulkan-demo ${SOURCES})

find_package(Vulkan REQUIRED)
target_include_directories(vulkan-demo PUBLIC ${Vulkan_INCLUDE_DIRS})

set_target_properties(vulkan-demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY    "${CMAKE_SOURCE_DIR}/bin"
)

target_include_directories(vulkan-demo 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(vulkan-demo
    PUBLIC      -lstdc++
    PRIVATE     glfw
    PRIVATE     glm
    PRIVATE     Vulkan::Vulkan
)