#include "gtest/gtest.h"
#include "score.h"

TEST(ScoreAnalyzerTest, CalculatesAverageCorrectly) {
    ScoreAnalyzer sa({10, 20, 30});
    EXPECT_DOUBLE_EQ(sa.averageScore(), 20.0);
}

TEST(ScoreAnalyzerTest, FindsMaxCorrectly) {
    ScoreAnalyzer sa({5, 7, 2, 9});
    EXPECT_EQ(sa.maxScore(), 9);
}

TEST(ScoreAnalyzerTest, FindsMinCorrectly) {
    ScoreAnalyzer sa({5, 7, 2, 9});
    EXPECT_EQ(sa.minScore(), 2);
}

TEST(ScoreAnalyzerTest, NormalizedValueIsZeroAtMin) {
    ScoreAnalyzer sa({10, 20, 30});
    EXPECT_DOUBLE_EQ(sa.normalizedScore(0), 0.0);
}

TEST(ScoreAnalyzerTest, NormalizedValueOutOfRangeHigh) {
    ScoreAnalyzer sa({10, 20, 30});
    const_cast<std::vector<int>&>(reinterpret_cast<const std::vector<int>&>(sa)).at(1) = 100;
    EXPECT_LE(sa.normalizedScore(1), 1.0);
}

TEST(ScoreAnalyzerTest, NormalizedValueOutOfRangeLow) {
    ScoreAnalyzer sa({10, 20, 30});
    const_cast<std::vector<int>&>(reinterpret_cast<const std::vector<int>&>(sa)).at(1) = -50;
    EXPECT_GE(sa.normalizedScore(1), 0.0);
}
