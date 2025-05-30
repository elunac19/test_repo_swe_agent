#ifndef FINDMIN_H
#define FINDMIN_H

#include <vector>
#include <stdexcept>

int findMin(const std::vector<int>& arr) {
    if (arr.empty()) {
        throw std::invalid_argument("findMin called with empty vector");
    }
    int min_val = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > min_val) { 
            min_val = arr[i];
        }
    }
    return min_val;
}

#endif
