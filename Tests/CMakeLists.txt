project(Tests LANGUAGES CXX)

add_executable(Tests
               src/Tests.cpp
               src/DayFourTest.cpp src/DayFiveTest.cpp src/DaySixTest.cpp)

target_link_libraries(Tests PRIVATE
                      Catch2::Catch2
                      Advent)

catch_discover_tests(Tests)
