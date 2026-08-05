#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n);
        vector<int> freq(n + 1, 0);
        int commonCount = 0;

        for (int i = 0; i < n; ++i) {
            // Process element from A
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                commonCount++;
            }

            // Process element from B
            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                commonCount++;
            }

            // Store the count for the current prefix
            C[i] = commonCount;
        }

        return C;
    }
};