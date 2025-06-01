#include "gtest/gtest.h"
#include "statistics.h"

// Caso con valores positivos
TEST(StatisticsTest, HandlesPositiveNumbersMean) {
    Statistics stats({1.0, 2.0, 3.0, 4.0, 5.0});
    EXPECT_DOUBLE_EQ(stats.mean(), 3.0);
}

// Caso con valores negativos
TEST(StatisticsTest, HandlesNegativeNumbersMedian) {
    Statistics stats({-5.0, -1.0, -3.0});
    EXPECT_DOUBLE_EQ(stats.median(), -3.0);
}

// Caso con un solo número (todo debe ser 0 excepto la media)
TEST(StatisticsTest, SingleElement) {
    Statistics stats({7.0});
    EXPECT_DOUBLE_EQ(stats.mean(), 7.0);
    EXPECT_DOUBLE_EQ(stats.median(), 7.0);
    EXPECT_DOUBLE_EQ(stats.variance(), 0.0);
    EXPECT_DOUBLE_EQ(stats.standardDeviation(), 0.0);
}

// Excepción en vector vacío
TEST(StatisticsTest, ThrowsOnEmptyVector) {
    EXPECT_THROW(Statistics stats({}), std::invalid_argument);
}


// Varianza (esta fallará porque está mal el denominador)
TEST(StatisticsTest, FailsOnSampleVariance) {
    Statistics stats({1.0, 2.0, 3.0});
    // Esperamos varianza muestral: 1.0
    EXPECT_DOUBLE_EQ(stats.variance(), 1.0);
}

// Desviación estándar (fallará por el mismo bug)
TEST(StatisticsTest, FailsOnStandardDeviation) {
    Statistics stats({1.0, 2.0, 3.0});
    // std::sqrt(1.0) == 1.0
    EXPECT_DOUBLE_EQ(stats.standardDeviation(), 1.0);
}