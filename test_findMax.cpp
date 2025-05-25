#include "gtest/gtest.h" // GoogleTest header
#include "findMax.h"     // Your header file with the findMax function

// Test Suite for findMax function
// The first parameter is the test suite name, and the second is the test case name.

// Test case for a typical vector with positive numbers
TEST(FindMaxTest, HandlesPositiveNumbers) {
    std::vector<int> nums = {3, 5, 1, 8, 2};
    EXPECT_EQ(findMax(nums), 8); // Checks if findMax(nums) returns 8
}

// Test case for a vector with negative numbers
TEST(FindMaxTest, HandlesNegativeNumbers) {
    std::vector<int> nums = {-3, -5, -1, -8, -2};
    EXPECT_EQ(findMax(nums), -1);
}

// Test case for a vector with mixed positive and negative numbers, including zero
TEST(FindMaxTest, HandlesMixedNumbers) {
    std::vector<int> nums = {-3, 5, -1, 0, 2, -10};
    EXPECT_EQ(findMax(nums), 5);
}

// Test case for a vector with a single element
TEST(FindMaxTest, HandlesSingleElementVector) {
    std::vector<int> nums = {42};
    EXPECT_EQ(findMax(nums), 42);
}

// Test case for a vector with all elements being the same
TEST(FindMaxTest, HandlesAllSameElements) {
    std::vector<int> nums = {7, 7, 7, 7};
    EXPECT_EQ(findMax(nums), 7);
}

// Test case for an empty vector, expecting an exception
TEST(FindMaxTest, HandlesEmptyVectorThrowsException) {
    std::vector<int> nums = {};
    EXPECT_THROW(findMax(nums), std::invalid_argument);
}
// It's good practice to also test for large numbers if applicable,
// though this tests the algorithm's correctness more than int limits.
TEST(FindMaxTest, HandlesLargeNumbers) {
    std::vector<int> nums = {1000000, 2000000, 500000};
    EXPECT_EQ(findMax(nums), 2000000);
}