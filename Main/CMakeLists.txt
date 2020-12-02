project(Main LANGUAGES CXX)

add_executable(Main
               src/Main.cpp
               src/Main.h
               src/Utilites.h
               src/Utilites.cpp src/AdventDayOne.cpp src/AdventDayOne.h src/AdventDayTwo.cpp src/AdventDayTwo.h)

#target_include_directories(Main PRIVATE ${raylib_INCLUDE_DIRS})

target_link_libraries(Main PRIVATE fmt::fmt spdlog::spdlog)