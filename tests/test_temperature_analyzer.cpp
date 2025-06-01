#include "gtest/gtest.h"
#include "temperature_analyzer.h"

// Test básico de promedio con temperaturas normales
TEST(TemperatureAnalyzerTest, HandlesNormalAverage) {
    TemperatureAnalyzer ta({10.0, 20.0, 30.0});
    EXPECT_DOUBLE_EQ(ta.getAverage(), 20.0);
}

// Test básico de mínimo
TEST(TemperatureAnalyzerTest, FindsMinCorrectly) {
    TemperatureAnalyzer ta({5.0, -2.0, 7.0});
    EXPECT_DOUBLE_EQ(ta.getMin(), -2.0);
}

// Test básico de máximo
TEST(TemperatureAnalyzerTest, FindsMaxCorrectly) {
    TemperatureAnalyzer ta({5.0, -2.0, 7.0});
    EXPECT_DOUBLE_EQ(ta.getMax(), 7.0);
}

// Test cuenta cuántos están arriba de cierto umbral
TEST(TemperatureAnalyzerTest, CountsAboveThresholdCorrectly) {
    TemperatureAnalyzer ta({10.0, 20.0, 30.0});
    EXPECT_EQ(ta.countAbove(15.0), 2);
}
