#include <iostream>
#include <vector>
#include <cstdlib>

void simulate(int steps) {
    std::vector<int> states(10, 0);

    for (int i = 0; i < steps; ++i) {
        for (int j = 0; j < states.size(); ++j) {
            if (rand() % 2 == 0) {
                states[j]++;
            } else {
                states[j]--;
            }
        }

        std::cout << "Step " << i << ": ";
        for (int val : states) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    simulate(5);
    return 0;
}
