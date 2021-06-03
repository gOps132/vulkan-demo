cmake_minimum_required(VERSION 3.14)
project(vulkan-demo
    DESCRIPTION "Just me learning some vulkan"
)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)

set(VULKAN_DEMO_SOURCES 
    src/Application.cpp
)

add_executable(vulkan-demo ${VULKAN_DEMO_SOURCES})

find_package(Vulkan REQUIRED)
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