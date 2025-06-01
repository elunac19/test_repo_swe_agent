#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <stdexcept>

class Statistics {
public:
    Statistics(const std::vector<double>& data) : values(data) {
        if (values.empty()) {
            throw std::invalid_argument("Data set cannot be empty.");
        }
    }

    double mean() const {
        return std::accumulate(values.begin(), values.end(), 0.0) / values.size();
    }

    double median() const {
        std::vector<double> sorted = values;
        std::sort(sorted.begin(), sorted.end());
        size_t mid = sorted.size() / 2;

        if (sorted.size() % 2 == 0) {
            return (sorted[mid - 1] + sorted[mid]) / 2.0;
        } else {
            return sorted[mid];
        }
    }

    double variance() const {
        if (values.size() == 1) {
            return 0.0;
        }

        double avg = mean();
        double var = 0.0;

        for (const auto& v : values) {
            var += std::pow(v - avg, 2);
        }

        return var / (values.size() - 1);
    }

    double standardDeviation() const {
        return std::sqrt(variance());
    }

private:
    std::vector<double> values;
};

#endif
