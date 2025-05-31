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

// Con números grandes
TEST(FindMinTest, HandlesLargeNumbers) {
    std::vector<int> nums = {1000000, 2000000, 500000};
    EXPECT_EQ(findMin(nums), 500000);
}


// Caso típico con números positivos
TEST(FindMinTest, HandlesPositiveNumbers) {
    std::vector<int> nums = {5, 3, 8, 2, 10};
    EXPECT_EQ(findMin(nums), 2);
}

// Caso con solo negativos
TEST(FindMinTest, HandlesNegativeNumbers) {
    std::vector<int> nums = {-3, -5, -1, -8, -2};
    EXPECT_EQ(findMin(nums), -8);
}

// Mixto con positivos y negativos
TEST(FindMinTest, HandlesMixedNumbers) {
    std::vector<int> nums = {-3, 5, -1, 0, 2, -10};
    EXPECT_EQ(findMin(nums), -10);
}