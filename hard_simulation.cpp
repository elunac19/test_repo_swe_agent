#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>

class Simulator {
public:
    Simulator(int steps, int vector_size, unsigned int seed);
    void run();
    void print_state();
private:
    int steps;
    int vector_size;
    std::vector<int> states;
    unsigned int seed;
    std::mt19937 rng;
};

Simulator::Simulator(int steps, int vector_size, unsigned int seed) : steps(steps), vector_size(vector_size), seed(seed), rng(seed) {
    states.resize(vector_size, 0);
}

void Simulator::run() {
    for (int i = 0; i < steps; ++i) {
        for (int j = 0; j < states.size(); ++j) {
            std::uniform_int_distribution<int> dist(0, 1);
            if (dist(rng) == 0) {
                states[j]++;
            } else {
                states[j]--;
            }
        }
        print_state();
    }
}

void Simulator::print_state() {
    std::cout << "Step " << steps << ": ";
    for (int val : states) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}




int main() {
    Simulator sim(5, 10, 0);
    sim.run();
    return 0;
}
