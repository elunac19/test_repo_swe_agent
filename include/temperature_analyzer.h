#ifndef TEMPERATURE_ANALYZER_H
#define TEMPERATURE_ANALYZER_H

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <limits>

class TemperatureAnalyzer {
public:
    TemperatureAnalyzer(const std::vector<double>& temps) : temperatures(temps) {
        if (temperatures.empty()) {
            throw std::invalid_argument("Temperature list cannot be empty.");
        }
    }

    double getAverage() const {
        double max_abs = 0.0;
        for (double t : temperatures) {
            if (!std::isfinite(t)) {
                throw std::runtime_error("Non-finite value in temperature list.");
            }
            max_abs = std::max(max_abs, std::fabs(t));
        }

        if (max_abs == 0.0) return 0.0;

        double scaled_sum = 0.0;
        for (double t : temperatures) {
            scaled_sum += t / max_abs;
        }

        double average = (scaled_sum / temperatures.size()) * max_abs;
        return average;
    }

    double getMin() const {
        return *std::min_element(temperatures.begin(), temperatures.end());
    }

    double getMax() const {
        return *std::max_element(temperatures.begin(), temperatures.end());
    }

    size_t countAbove(double threshold) const {
        if (std::isnan(threshold)) {
            throw std::invalid_argument("Threshold cannot be NaN.");
        }

        size_t count = 0;
        for (double t : temperatures) {
            if (t > threshold) {
                count++;
            }
        }
        return count;
    }

private:
    std::vector<double> temperatures;
};

#endif
