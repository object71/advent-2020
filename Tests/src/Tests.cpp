//
// Created by capit on 12/2/2020.
//

#include <gtest/gtest.h>

TEST(UtilityTests, ValidateTestingWorks) {
    ASSERT_TRUE(true);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}