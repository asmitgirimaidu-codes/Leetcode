#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        std::vector<int> best_result(k, 0);

        int start = std::max(0, k - n);
        int end = std::min(k, m);

        for (int i = start; i <= end; ++i) {
            std::vector<int> seq1 = maxSubsequence(nums1, i);
            std::vector<int> seq2 = maxSubsequence(nums2, k - i);
            std::vector<int> merged = merge(seq1, seq2);
            
            if (isGreater(merged, 0, best_result, 0)) {
                best_result = merged;
            }
        }

        return best_result;
    }

private:
    // Helper 1: Find the maximum subsequence of length `k` using a monotonic stack
    std::vector<int> maxSubsequence(const std::vector<int>& nums, int k) {
        std::vector<int> stack;
        int drop = nums.size() - k;
        
        for (int num : nums) {
            while (!stack.empty() && stack.back() < num && drop > 0) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }
        
        stack.resize(k);
        return stack;
    }

    // Helper 2: Merge two sequences to form the largest possible combined number
    std::vector<int> merge(const std::vector<int>& seq1, const std::vector<int>& seq2) {
        std::vector<int> res;
        auto it1 = seq1.begin();
        auto it2 = seq2.begin();
        
        while (it1 != seq1.end() || it2 != seq2.end()) {
            if (isGreater(seq1, std::distance(seq1.begin(), it1), seq2, std::distance(seq2.begin(), it2))) {
                res.push_back(*it1++);
            } else {
                res.push_back(*it2++);
            }
        }
        
        return res;
    }

    // Helper 3: Lexicographical comparison between two vector slices
    bool isGreater(const std::vector<int>& seq1, int i, const std::vector<int>& seq2, int j) {
        while (i < seq1.size() && j < seq2.size()) {
            if (seq1[i] != seq2[j]) {
                return seq1[i] > seq2[j];
            }
            i++;
            j++;
        }
        return (i != seq1.size());
    }
};