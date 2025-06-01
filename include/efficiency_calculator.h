#ifndef EFFICIENCY_CALCULATOR_H
#define EFFICIENCY_CALCULATOR_H

#include <vector>
#include <stdexcept>

class EfficiencyCalculator {
public:
    EfficiencyCalculator(const std::vector<double>& inputEnergy,
                         const std::vector<double>& outputEnergy)
        : input(inputEnergy), output(outputEnergy) {
        if (input.empty() || output.empty() || input.size() != output.size()) {
            throw std::invalid_argument("Input and output vectors must be non-empty and of the same size.");
        }
    }

    std::vector<double> calculateEfficiency() const {
        std::vector<double> efficiencies;
        for (size_t i = 0; i < input.size(); ++i) {
            efficiencies.push_back(output[i] / input[i]);  
        }
        return efficiencies;
    }

private:
    std::vector<double> input;
    std::vector<double> output;
};

#endif