project(Tests LANGUAGES CXX)

add_executable(Tests
               src/Tests.cpp
               src/DayFourTest.cpp src/DayFiveTest.cpp src/DaySixTest.cpp src/DaySevenTest.cpp src/DayEightTest.cpp src/DayNineTest.cpp src/DayElevenTest.cpp src/DayTwelveTest.cpp)

target_link_libraries(Tests PRIVATE
                      Catch2::Catch2
                      Advent)

catch_discover_tests(Tests)

if (IS_MAIN)
#    add_custom_command(TARGET Tests POST_BUILD
#                       COMMAND ctest -C Debug
#                       WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#                       )
endif ()