#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        // Sort arr2 to enable binary search
        std::sort(arr2.begin(), arr2.end());
        int distanceValue = 0;

        for (int x : arr1) {
            // Find the first element in arr2 that is >= x
            auto it = std::lower_bound(arr2.begin(), arr2.end(), x);
            
            bool isValid = true;
            
            // Check the element at or immediately above x
            if (it != arr2.end() && std::abs(*it - x) <= d) {
                isValid = false;
            }
            
            // Check the element immediately below x
            if (isValid && it != arr2.begin()) {
                auto prev_it = std::prev(it);
                if (std::abs(*prev_it - x) <= d) {
                    isValid = false;
                }
            }
            
            if (isValid) {
                distanceValue++;
            }
        }

        return distanceValue;
    }
};