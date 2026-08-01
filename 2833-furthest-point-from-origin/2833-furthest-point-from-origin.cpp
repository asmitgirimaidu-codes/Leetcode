class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int leftCount = 0, rightCount = 0, wildcardCount = 0;
        
        for (char c : moves) {
            if (c == 'L') leftCount++;
            else if (c == 'R') rightCount++;
            else wildcardCount++;
        }
        
        return abs(leftCount - rightCount) + wildcardCount;
    }
};