cmake_minimum_required(VERSION 3.10)

project(XenoEngine VERSION 0.01)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

if (UNIX)
find_package(PkgConfig REQUIRED)

pkg_search_module(GLFW REQUIRED glfw3)

endif (UNIX)

include_directories(${GLFW_INCLUDE_DIRS})

set(ALL_LIBS
	${OPENGL_LIBRARY}
	${GLFW_LIBRARIES}
)


set(GRAPHICS_SOURCES
	src/Graphics/Window/Window.cpp)

set(SOURCES
	{GRAPHICS_SOURCES})

# add_executable(XenoEngine
# src/main.cpp
# src/Graphics/Window/Window.cpp)

add_library(XenoEngine
src/Graphics/Window/Window.cpp)

target_link_libraries(XenoEngine ${ALL_LIBS})
