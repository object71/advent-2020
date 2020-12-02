project(Advent LANGUAGES CXX)

add_library(Advent STATIC
            src/Utilites.h
            src/Utilites.cpp
            src/AdventDayOne.cpp
            src/AdventDayOne.h
            src/AdventDayTwo.cpp
            src/AdventDayTwo.h)

target_link_libraries(Advent PUBLIC fmt::fmt spdlog::spdlog)

target_include_directories(Advent
                           PUBLIC
                           $<INSTALL_INTERFACE:src>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
                           )

#target_include_directories(Main PRIVATE ${raylib_INCLUDE_DIRS})

