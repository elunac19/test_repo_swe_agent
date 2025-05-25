#ifndef FINDMAX_H
#define FINDMAX_H

#include <iostream>
#include <vector>

int findMax(const std::vector<int>& nums) {
  if (nums.size() == 0) {
      return -9999999;
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