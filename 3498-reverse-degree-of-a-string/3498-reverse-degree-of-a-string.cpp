class Solution {
public:
    int reverseDegree(string s) {
        int totalDegree = 0;
        for (int i = 0; i < s.length(); ++i) {
            int reversedAlphabetPos = 26 - (s[i] - 'a');
            int stringPos = i + 1;
            totalDegree += reversedAlphabetPos * stringPos;
        }
        return totalDegree;
    }
};