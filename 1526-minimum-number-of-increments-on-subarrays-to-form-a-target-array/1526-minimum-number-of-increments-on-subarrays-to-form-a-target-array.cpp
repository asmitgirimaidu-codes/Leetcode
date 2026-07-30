#include <vector>
#include <algorithm>

class Solution {
public:
    int minNumberOperations(std::vector<int>& target) {
        int operations = target[0];
        
        for (size_t i = 1; i < target.size(); ++i) {
            // If the current element is greater than the previous one,
            // we need additional operations to cover the difference.
            if (target[i] > target[i - 1]) {
                operations += target[i] - target[i - 1];
            }
        }
        
        return operations;
    }
};