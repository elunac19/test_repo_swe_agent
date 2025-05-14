#include <iostream>
#include <vector>
#include <random>

class Simulator {
public:
    Simulator(int vector_size, unsigned int seed) : vector_size_(vector_size), seed_(seed) {
        states_.resize(vector_size_, 0);
        rng_.seed(seed_);
    }

    void step() {
        for (int j = 0; j < vector_size_; ++j) {
            if (std::uniform_int_distribution<>(0, 1)(rng_) == 0) {
                states_[j]++;
            } else {
                states_[j]--;
            }
        }
    }

    const std::vector<int>& get_states() const {
        return states_;
    }

private:

    int vector_size_;
    unsigned int seed_;
    std::vector<int> states_;
    std::mt19937 rng_;
};

int main() {
    Simulator sim(10, 42);
    for (int i = 0; i < 5; ++i) {
        sim.step();
        std::cout << "Step " << i << ": ";
        for (int val : sim.get_states()) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
