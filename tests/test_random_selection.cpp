#include "gtest/gtest.h"
#include "random_selection.h" // Include the header file we just created
#include <algorithm> // For std::sort

namespace RandomAlgorithms {
namespace Testing {

// Fixture for common test setup if needed, but for now, direct tests are fine.
class RandomSelectorTest : public ::testing::Test {
protected:
    RandomSelector selector;
};


TEST_F(RandomSelectorTest, HandlesSingleElementArray) {
    std::vector<int> arr = {42};
    EXPECT_EQ(selector.selectKthSmallest(arr, 0), 42);
}

TEST_F(RandomSelectorTest, ThrowsExceptionForEmptyArray) {
    std::vector<int> arr;
    EXPECT_THROW(selector.selectKthSmallest(arr, 0), std::invalid_argument);
}

TEST_F(RandomSelectorTest, ThrowsExceptionForKOutOfBounds) {
    std::vector<int> arr = {1, 2, 3};
    EXPECT_THROW(selector.selectKthSmallest(arr, 3), std::out_of_range); // k too high
    EXPECT_THROW(selector.selectKthSmallest(arr, 100), std::out_of_range); // k much too high
}

TEST_F(RandomSelectorTest, FindsKthSmallestInSortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(selector.selectKthSmallest(arr, 0), 1);
    EXPECT_EQ(selector.selectKthSmallest(arr, 4), 5);
    EXPECT_EQ(selector.selectKthSmallest(arr, 9), 10);
}

TEST_F(RandomSelectorTest, FindsKthSmallestInUnsortedArray) {
    std::vector<int> arr = {5, 2, 8, 1, 9, 3, 7, 4, 6, 0};
    EXPECT_EQ(selector.selectKthSmallest(arr, 0), 0);
    EXPECT_EQ(selector.selectKthSmallest(arr, 3), 3);
    EXPECT_EQ(selector.selectKthSmallest(arr, 5), 5);
    EXPECT_EQ(selector.selectKthSmallest(arr, 9), 9);
}

TEST_F(RandomSelectorTest, HandlesDuplicateElements) {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    // Sorted: 1, 1, 2, 3, 3, 4, 5, 5, 6, 9
    EXPECT_EQ(selector.selectKthSmallest(arr, 0), 1);
    EXPECT_EQ(selector.selectKthSmallest(arr, 1), 1);
    EXPECT_EQ(selector.selectKthSmallest(arr, 2), 2);
    EXPECT_EQ(selector.selectKthSmallest(arr, 4), 3);
    EXPECT_EQ(selector.selectKthSmallest(arr, 9), 9);
}

// Test with a larger, randomly generated array
TEST_F(RandomSelectorTest, LargerRandomArrayTest) {
    std::vector<int> arr(1000);
    std::generate(arr.begin(), arr.end(), [](){ return rand() % 10000; }); // Populate with random numbers

    // Create a sorted copy to verify against
    std::vector<int> sorted_arr = arr;
    std::sort(sorted_arr.begin(), sorted_arr.end());

    // Test several random k values
    for (int i = 0; i < 10; ++i) {
        size_t k = rand() % 1000; // Random k between 0 and 999
        EXPECT_EQ(selector.selectKthSmallest(arr, k), sorted_arr[k])
            << "Mismatch for k = " << k;
    }
}

}
}