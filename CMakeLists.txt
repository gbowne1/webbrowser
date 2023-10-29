cmake_minimum_required(VERSION 3.13)

project(webbrowser
		VERSION 1.0.0
		DESCRIPTION "A webbrowser for ClassicOS"
		HOMEPAGE_URL "https://github.com/gbowne1/webbrowser"
		LANGUAGES CXX)

		include(CTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

set(IS_OS_WINDOWS FALSE)
set(IS_OS_LINUX FALSE)
set(IS_OS_MAC FALSE)

if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
	set(IS_OS_WINDOWS TRUE)
	message("Building on the Windows operating system.")
elseif (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
	set(IS_OS_LINUX TRUE)
	message("Building on the Linux operating system.")
elseif (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin")
	set(IS_OS_MAC TRUE)
	message("Building on the Mac operating system.")
endif ()

if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
	set(CMAKE_CXX_FLAGS "")
	set(CMAKE_CXX_FLAGS_DEBUG "")
	set(CMAKE_CXX_COMPILER /usr/bin/c++)
	set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
elseif (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
	set(CMAKE_CXX_FLAGS "")
	set(CMAKE_CXX_FLAGS_DEBUG "")
	set(CMAKE_CXX_COMPILER cl.exe)
	set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
elseif (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "BSD")
    set(CMAKE_CXX_FLAGS "")
    set(CMAKE_CXX_FLAGS_DEBUG "")
    set(CMAKE_CXX_COMPILER clang++)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
elseif (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin")
    set(CMAKE_CXX_FLAGS "")
    set(CMAKE_CXX_FLAGS_DEBUG "")
    set(CMAKE_CXX_COMPILER clang++)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

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

# Enable testing
enable_testing()