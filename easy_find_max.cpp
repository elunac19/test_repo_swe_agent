#include <iostream>
#include <vector>

int findMax(const std::vector<int>& nums) {
    int maxVal = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    return maxVal;
}

int main() {
    std::vector<int> nums = {3, 5, 1, 8, 2};
    std::cout << "Max value: " << findMax(nums) << std::endl;
    return 0;
}
