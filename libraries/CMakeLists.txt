set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_CPU_DEMOS OFF CACHE BOOL "" FORCE)
set(BUILD_BULLET2_DEMOS OFF CACHE BOOL "" FORCE)
set(BUILD_OPENGL3_DEMOS OFF CACHE BOOL "" FORCE)
set(BUILD_EXTRAS OFF CACHE BOOL "" FORCE)
set(BUILD_BULLET3 OFF CACHE BOOL "" FORCE)
set(BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
set(CMAKE_BUILD_TYPE RELEASE FORCE)
add_subdirectory(glfw)
add_subdirectory(bullet3)

include("glad/glad/CMakeLists.txt")
set(LIBRARY_INCLUDES
		"${madd_SOURCE_DIR}/libraries/glm"
		"${madd_SOURCE_DIR}/libraries/glfw/include"
		"${madd_SOURCE_DIR}/libraries/KHR"
		"${madd_SOURCE_DIR}/libraries/stb"
		"${madd_SOURCE_DIR}/libraries/glad"
		"${madd_SOURCE_DIR}/libraries/bullet3/src"
	PARENT_SCOPE)
