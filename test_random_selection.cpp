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

}
}