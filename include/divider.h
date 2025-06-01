#ifndef DIVIDER_H
#define DIVIDER_H

#include <vector>
#include <stdexcept>
#include <numeric>
#include <cmath>

class Divider {
public:
    Divider(const std::vector<int>& data) : values(data) {
        if (values.empty()) {
            throw std::invalid_argument("Data cannot be empty.");
        }
    }

    std::vector<double> divideByTotal() const {
        int total = std::accumulate(values.begin(), values.end(), 0);

        if (total == 0) {
            throw std::runtime_error("Sum of elements is zero; division undefined.");
        }

        std::vector<double> result;
        for (int val : values) {
            result.push_back(static_cast<double>(val) / total);
        }
        return result;
    }

private:
    std::vector<int> values;
};

#endif
