project(Tests LANGUAGES CXX)

add_executable(Tests
               src/Tests.cpp
               )

target_link_libraries(Tests PRIVATE
                      GTest::gmock
                      GTest::gtest
                      Advent)

add_test(
        NAME Tests
        COMMAND Tests
)

