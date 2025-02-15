cmake_minimum_required(VERSION 3.16)

project(Advent2020)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(IS_MAIN (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR}))


find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

find_package(PythonInterp REQUIRED)

include(CTest)
include(Catch)

if (WIN32)
    add_compile_definitions(WINDOWS=1)
endif ()

if (UNIX AND NOT APPLE)
    add_compile_definitions(LINUX=1)
endif ()

if (APPLE)
    add_compile_definitions(APPLE=1)
endif ()

if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    add_compile_definitions(_DEBUG=1)
else ()
    add_compile_definitions(NDEBUG=1)
endif (${CMAKE_BUILD_TYPE} MATCHES Debug)

add_subdirectory(Advent)
add_subdirectory(Main)

if (IS_MAIN)
    add_subdirectory(Tests)
    
    include(InstallRequiredSystemLibraries)
    set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
    set(CPACK_PACKAGE_VERSION_MAJOR "1")
    set(CPACK_PACKAGE_VERSION_MINOR "0")
    include(CPack)
endif ()

add_custom_target(Solution ALL
                  COMMENT "Executiong post build scripts \"${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/post_build.py\""
                  COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/post_build.py ${Main_BINARY_DIR}
                  COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/post_build.py ${Tests_BINARY_DIR}
                  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

