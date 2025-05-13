#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>

std::optional<int> findMax(const std::vector<int>& nums) {
    if (nums.empty()) {
        return std::nullopt;
    }
    auto maxIt = std::max_element(nums.begin(), nums.end());
    return *maxIt;

}

int main() {
    std::vector<int> nums = {3, 5, 1, 8, 2};
    auto result = findMax(nums);
    if (result.has_value()) {
        std::cout << "Max value: " << result.value() << std::endl;
    } else {
        std::cout << "Vector is empty." << std::endl;
    }

    std::vector<int> emptyVec = {};
    auto emptyResult = findMax(emptyVec);
    if (emptyResult.has_value()) {
        std::cout << "Max value: " << emptyResult.value() << std::endl;
    } else {
        std::cout << "Vector is empty." << std::endl;
    }

    return 0;
}

