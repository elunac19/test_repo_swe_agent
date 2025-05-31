#ifndef FINDMAX_H
#define FINDMAX_H

#include <iostream>
#include <vector>
#include <stdexcept>

int findMax(const std::vector<int>& nums) {
  if (nums.size() == 0) {
      throw std::invalid_argument("findMax called with empty vector");
  }
    int maxVal = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    return maxVal;
}
#endif