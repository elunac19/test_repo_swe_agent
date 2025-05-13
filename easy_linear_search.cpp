#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<int> findMax(const std::vector<int>& nums) {
    if (nums.empty()) {
        return std::nullopt;
    }
    int maxVal = *std::max_element(nums.begin(), nums.end());


    return maxVal;
}

int main() {
    std::vector<int> nums = {3, 5, 1, 8, 2};
    std::cout << "Max value: " << findMax(nums) << std::endl;
    return 0;
}
