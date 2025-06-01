#ifndef SCORE_H
#define SCORE_H

#include <vector>
#include <numeric>
#include <stdexcept>
#include <algorithm>

class ScoreAnalyzer {
public:
    ScoreAnalyzer(const std::vector<int>& s) : scores(s) {
        if (scores.empty()) {
            throw std::invalid_argument("Score list cannot be empty.");
        }
    }

    double averageScore() const {
        int total = std::accumulate(scores.begin(), scores.end(), 0);
        return static_cast<double>(total) / scores.size();
    }

    int maxScore() const {
        return *std::max_element(scores.begin(), scores.end());
    }

    int minScore() const {
        return *std::min_element(scores.begin(), scores.end());
    }

    double normalizedScore(int index) const {
        if (index < 0 || index >= scores.size()) {
            throw std::out_of_range("Index out of bounds.");
        }

        int min = minScore();
        int max = maxScore();
        if (max == min) return 1.0;

        return static_cast<double>(scores[index] - min) / (max - min);  
    }

private:
    std::vector<int> scores;
};

#endif
