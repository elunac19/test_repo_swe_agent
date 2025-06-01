#include "gtest/gtest.h"
#include "efficiency_calculator.h"

// Casos normales — deberían pasar incluso con bug
TEST(EfficiencyCalculatorTest, CalculatesCorrectEfficiencies) {
    EfficiencyCalculator ec({100.0, 200.0, 300.0}, {80.0, 150.0, 270.0});
    std::vector<double> expected = {0.8, 0.75, 0.9};
    EXPECT_EQ(ec.calculateEfficiency(), expected);
}

TEST(EfficiencyCalculatorTest, HandlesPerfectEfficiency) {
    EfficiencyCalculator ec({50.0, 70.0}, {50.0, 70.0});
    std::vector<double> expected = {1.0, 1.0};
    EXPECT_EQ(ec.calculateEfficiency(), expected);
}

TEST(EfficiencyCalculatorTest, HandlesFractionalEfficiency) {
    EfficiencyCalculator ec({120.0, 80.0}, {60.0, 40.0});
    std::vector<double> expected = {0.5, 0.5};
    EXPECT_EQ(ec.calculateEfficiency(), expected);
}
