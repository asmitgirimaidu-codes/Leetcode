class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check if one rectangle is to the left, right, above, or below the other
        bool isLeft = rec1[2] <= rec2[0];
        bool isRight = rec1[0] >= rec2[2];
        bool isBelow = rec1[3] <= rec2[1];
        bool isAbove = rec1[1] >= rec2[3];
        
        // If it's not separated in any of these 4 directions, they overlap
        return !(isLeft || isRight || isBelow || isAbove);
    }
};