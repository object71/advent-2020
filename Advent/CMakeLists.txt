project(Advent LANGUAGES CXX)

add_library(Advent STATIC
            src/strutil.h
            src/Utilities.h
            src/Utilities.cpp
            src/DayOne.cpp
            src/DayOne.h
            src/DayTwo.cpp
            src/DayTwo.h src/DayThree.cpp src/DayThree.h src/DayFour.cpp src/DayFour.h src/DayFive.cpp src/DayFive.h src/DaySix.cpp src/DaySix.h src/DaySeven.cpp src/DaySeven.h src/DayEight.cpp src/DayEight.h)

target_link_libraries(Advent PUBLIC fmt::fmt spdlog::spdlog)

target_include_directories(Advent
                           PUBLIC
                           $<INSTALL_INTERFACE:src>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
                           )

#target_include_directories(Main PRIVATE ${raylib_INCLUDE_DIRS})

