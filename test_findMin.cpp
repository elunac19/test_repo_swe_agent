#include "gtest/gtest.h"
#include "findMin.h"

// Solo un elemento
TEST(FindMinTest, HandlesSingleElementVector) {
    std::vector<int> nums = {42};
    EXPECT_EQ(findMin(nums), 42);
}

// Todos iguales
TEST(FindMinTest, HandlesAllSameElements) {
    std::vector<int> nums = {7, 7, 7, 7};
    EXPECT_EQ(findMin(nums), 7);
}

// Vector vacío → debe lanzar excepción
TEST(FindMinTest, HandlesEmptyVectorThrowsException) {
    std::vector<int> nums = {};
    EXPECT_THROW(findMin(nums), std::invalid_argument);
}
