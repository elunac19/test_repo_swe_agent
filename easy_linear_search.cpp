#include <vector>
#include <algorithm>
#include <optional>

std::optional<int> findMax(const std::vector<int>& nums) {
    if (nums.empty()) {
        return std::nullopt;
    }
    return *std::max_element(nums.begin(), nums.end());
}