#include <iostream>
#include <vector>
#include <random>

class Simulator {
public:
    Simulator(int steps, int vector_size, unsigned int seed) : steps(steps), vector_size(vector_size), seed(seed) {
        std::random_device rd;
        mt = std::mt19937(rd() + seed);
        dist = std::uniform_int_distribution<>(0, 1);
        states.resize(vector_size, 0);
    }

    void run() {
        for (int i = 0; i < steps; ++i) {
            updateState();
            printState(i);
        }
    }

private:
    void updateState() {
        for (int j = 0; j < states.size(); ++j) {
            if (dist(mt) == 1) {
                states[j]++;
            } else {
                states[j]--;
            }
        }
    }

    void printState(int step) {
        std::cout << "Step " << step << ": ";
        for (int val : states) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    int steps;
    int vector_size;
    unsigned int seed;
    std::vector<int> states;
    std::mt19937 mt;
    std::uniform_int_distribution<> dist;
};

int main() {
    Simulator sim(5, 10, 0);
    sim.run();
    return 0;
}
