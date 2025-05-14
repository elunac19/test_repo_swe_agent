#include <iostream>
#include <algorithm>
#include <optional>
#include <vector>

std::optional<int> findMax(const std::vector<int>& nums) {
    if (nums.empty()) {
        return std::nullopt;
    }
    int maxVal = nums[0];
    return *std::max_element(nums.begin(), nums.end());

}

int main() {
    std::vector<int> nums = {3, 5, 1, 8, 2};
    auto result = findMax(nums);
    if (result) {
        std::cout << "Max value: " << *result << std::endl;
    } else {
        std::cout << "Max value: (empty vector)" << std::endl;
    }
    return 0;
}
