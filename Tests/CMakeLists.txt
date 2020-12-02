project(Tests LANGUAGES CXX)

add_executable(Tests
               src/Tests.cpp
               )

target_link_libraries(Tests PUBLIC
                      GTest::gmock
                      GTest::gtest
                      MainLib)

add_test(
        NAME Tests
        COMMAND Tests
)

