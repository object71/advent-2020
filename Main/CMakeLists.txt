project(Main LANGUAGES CXX)

SET(Sources
    src/Main.cpp
    src/Main.h
    src/Utilites.h
    src/Utilites.cpp
    src/AdventDayOne.cpp
    src/AdventDayOne.h
    src/AdventDayTwo.cpp
    src/AdventDayTwo.h
    )

add_executable(Main ${Sources})
target_link_libraries(Main PRIVATE fmt::fmt spdlog::spdlog)

add_library(MainLib STATIC ${Sources})
target_link_libraries(MainLib PRIVATE fmt::fmt spdlog::spdlog)

#target_include_directories(Main PRIVATE ${raylib_INCLUDE_DIRS})

