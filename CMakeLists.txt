cmake_minimum_required(VERSION 3.)

project(webbrowser
		VERSION 1.0.0
		DESCRIPTION "A webbrowser for ClassicOS"
		HOMEPAGE_URL "https://github.com/gbowne1/webbrowser"
		LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")

# Add source files
set(SOURCES
    src/main.cpp
    src/ui/window.cpp
    src/network/http.cpp
    src/rendering/html.cpp
    src/utils/string.cpp
    src/utils/file.cpp
)

# Add header files
set(HEADERS
    include/ui/window.h
    include/network/http.h
    include/rendering/html.h
    include/utils/string.h
    include/utils/file.h
)

# Add libraries
set(LIBRARIES
    libhttp
    libtcp
    libhtml
    libcss
    libstring
    libfile
)

# Add include directories
include_directories(include)

# Add libraries directories
link_directories(lib)

# Add executable
add_executable(web_browser ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(web_browser ${LIBRARIES})
