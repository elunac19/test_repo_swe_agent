#include "gtest/gtest.h"
#include "divider.h"

TEST(DividerTest, DividesByTotalCorrectly) {
    Divider d({1, 2, 3});
    std::vector<double> expected = {1.0 / 6, 2.0 / 6, 3.0 / 6};
    std::vector<double> result = d.divideByTotal();
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_NEAR(result[i], expected[i], 1e-6);
    }
}

TEST(DividerTest, HandlesNegativeValues) {
    Divider d({-1, -1, -2});
    std::vector<double> expected = {0.25, 0.25, 0.5};  
    std::vector<double> result = d.divideByTotal();
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_NEAR(result[i], expected[i], 1e-6);
    }
}

TEST(DividerTest, OneElementVector) {
    Divider d({10});
    std::vector<double> expected = {1.0};
    std::vector<double> result = d.divideByTotal();
    EXPECT_NEAR(result[0], expected[0], 1e-6);
}
