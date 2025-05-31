#ifndef RANDOM_SELECTION_H
#define RANDOM_SELECTION_H

#include <vector>
#include <algorithm> // For std::sort, std::swap
#include <random>    // For std::mt19937, std::uniform_int_distribution
#include <chrono>    // For std::chrono::system_clock

namespace RandomAlgorithms {

class RandomSelector {
public:
    /**
     * @brief Finds the k-th smallest element in a given vector using a randomized selection algorithm.
     * This is a variation of the quickselect algorithm aiming for better average pivot selection.
     *
     * @param arr The vector of integers to search within.
     * @param k The 0-indexed rank of the element to find (e.g., k=0 for smallest, k=arr.size()-1 for largest).
     * @return The k-th smallest element.
     * @throws std::out_of_range if k is out of bounds (k < 0 or k >= arr.size()).
     * @throws std::invalid_argument if arr is empty.
     */
    int selectKthSmallest(std::vector<int>& arr, size_t k);
    RandomSelector() : rng_(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count())) {}


private:
    std::mt19937 rng_; // Mersenne Twister random number generator

    /**
     * @brief Partitions the subarray around a chosen pivot. Elements less than the pivot
     * are moved to its left, and elements greater are moved to its right.
     * @param arr The vector to partition.
     * @param left The starting index of the subarray.
     * @param right The ending index of the subarray.
     * @param pivotIndex The index of the pivot element.
     * @return The final index of the pivot element after partitioning.
     */
    int partition(std::vector<int>& arr, int left, int right, int pivotIndex);

    /**
     * @brief Selects a pivot index. In this randomized median-of-medians variant,
     * it selects a random element from a small group of elements to represent the median.
     * @param arr The vector to select pivot from.
     * @param left The starting index of the subarray.
     * @param right The ending index of the subarray.
     * @return The index of the chosen pivot.
     */
    int choosePivotIndex(std::vector<int>& arr, int left, int right);

    /**
     * @brief Recursive helper function for selectKthSmallest.
     * @param arr The vector to search within.
     * @param left The starting index of the current subarray.
     * @param right The ending index of the current subarray.
     * @param k The 0-indexed rank of the element to find relative to the original array.
     * @return The k-th smallest element.
     */
    int quickSelectRecursive(std::vector<int>& arr, int left, int right, size_t k);
};

inline int RandomSelector::partition(std::vector<int>& arr, int left, int right, int pivotIndex) {
  int pivotValue = arr[pivotIndex];
  std::swap(arr[pivotIndex], arr[right]); // Move pivot to end
  int storeIndex = left;
  for (int i = left; i < right; ++i) {
      if (arr[i] < pivotValue) {
        std::swap(arr[storeIndex], arr[i]);
        storeIndex++; // <-- FIXED: Increment storeIndex ONLY when a smaller element is found and swapped.
      }
  }
  std::swap(arr[right], arr[storeIndex]); // Move pivot to its final sorted position
  return storeIndex;
}

inline int RandomSelector::choosePivotIndex(std::vector<int>& arr, int left, int right) {
    // For "randomized median-of-medians":
    // Take a small sample (e.g., 5 elements) and return the median of that sample.
    // If the subarray is too small, just return a random index.
    int numElements = right - left + 1;
    if (numElements <= 5) { // Base case for small arrays, just pick a random one
        std::uniform_int_distribution<> distrib(left, right);
        return distrib(rng_);
    }

    // Otherwise, create groups of 5, find their medians, and then find the median of *those* medians.
    // For simplicity and "medium complexity", we'll just pick 5 random indices and find their median.
    // A true median-of-medians would involve actual grouping and recursion.
    // This is a "randomized" approximation.

    std::vector<int> sample_indices;
    std::vector<int> sample_values;

    std::uniform_int_distribution<> distrib(left, right);
    for (int i = 0; i < std::min(5, numElements); ++i) {
        int rand_idx = distrib(rng_);
        sample_indices.push_back(rand_idx);
        sample_values.push_back(arr[rand_idx]);
    }

    std::sort(sample_values.begin(), sample_values.end());
    int median_of_sample = sample_values[sample_values.size() / 2];

    // Find the index of this median_of_sample in the original array within the current range
    for (int i = left; i <= right; ++i) {
        if (arr[i] == median_of_sample) {
            return i;
        }
    }
    // Should not happen if median_of_sample was taken from arr[left...right]
    return left; // Fallback
}

inline int RandomSelector::quickSelectRecursive(std::vector<int>& arr, int left, int right, size_t k) {
    if (left == right) {
        return arr[left];
    }

    int pivotIndex = choosePivotIndex(arr, left, right);
    pivotIndex = partition(arr, left, right, pivotIndex);

    if (k == static_cast<size_t>(pivotIndex)) {
        return arr[k];
    } else if (k < static_cast<size_t>(pivotIndex)) {
        return quickSelectRecursive(arr, left, pivotIndex - 1, k);
    } else {
        return quickSelectRecursive(arr, pivotIndex + 1, right, k);
    }
}

inline int RandomSelector::selectKthSmallest(std::vector<int>& arr, size_t k) {
    if (arr.empty()) {
        throw std::invalid_argument("Input array cannot be empty.");
    }
    if (k >= arr.size()) {
        throw std::out_of_range("k is out of bounds for the array size.");
    }
    // Make a copy to avoid modifying the original array if the user doesn't want that.
    // For algorithms that modify in place, a copy is often good practice for API.
    // Or, specify in documentation that it modifies the input. For this example, we'll copy.
    std::vector<int> temp_arr = arr;
    return quickSelectRecursive(temp_arr, 0, temp_arr.size() - 1, k);
}

} // namespace RandomAlgorithms

#endif // RANDOM_SELECTION_H