class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long area1 = (long long)(ax2 - ax1) * (ay2 - ay1);
        long long area2 = (long long)(bx2 - bx1) * (by2 - by1);
        
        long long overlapWidth = std::max(0LL, (long long)std::min(ax2, bx2) - std::max(ax1, bx1));
        long long overlapHeight = std::max(0LL, (long long)std::min(ay2, by2) - std::max(ay1, by1));
        
        long long intersectionArea = overlapWidth * overlapHeight;
        
        return area1 + area2 - intersectionArea;
    }
};