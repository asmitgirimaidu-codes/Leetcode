class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result;
        int depthA = 0, depthB = 0;
        
        for (char c : seq) {
            if (c == '(') {
                // Assign to the subsequence with the smaller current depth
                if (depthA <= depthB) {
                    depthA++;
                    result.push_back(0); // Part of subsequence A
                } else {
                    depthB++;
                    result.push_back(1); // Part of subsequence B
                }
            } else {
                // For closing bracket, close the one that was opened last (has larger depth)
                if (depthA >= depthB) {
                    depthA--;
                    result.push_back(0);
                } else {
                    depthB--;
                    result.push_back(1);
                }
            }
        }
        
        return result;
    }
};