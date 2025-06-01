#ifndef TEMPERATURE_ANALYZER_H
#define TEMPERATURE_ANALYZER_H

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cmath>

class TemperatureAnalyzer {
public:
    TemperatureAnalyzer(const std::vector<double>& temps) : temperatures(temps) {
        if (temperatures.empty()) {
            throw std::invalid_argument("Temperature list cannot be empty.");
        }
    }

    double getAverage() const {
        double sum = 0.0;
        for (double t : temperatures) {
            sum += t;
        }
        return sum / temperatures.size();
    }

    double getMin() const {
        return *std::min_element(temperatures.begin(), temperatures.end());
    }

    double getMax() const {
        return *std::max_element(temperatures.begin(), temperatures.end());
    }

    size_t countAbove(double threshold) const {
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
