#include <iostream>
#include <vector>

#include <algorithm>

std::optional<int> findMax(const std::vector<int>& nums) {
    if (nums.empty()) {
        return std::nullopt;
    }
    int maxVal = *std::max_element(nums.begin(), nums.end());
    return maxVal;
}

int main() {
    std::vector<int> nums = {3, 5, 1, 8, 2};
    auto result = findMax(nums);
    if (result.has_value()) {
        std::cout << "Max value: " << result.value() << std::endl;
    } else {
        std::cout << "Vector is empty. No maximum value." << std::endl;
    }
    return 0;
}
