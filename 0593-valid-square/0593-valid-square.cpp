class Solution {
public:
    long long getDistSq(vector<int>& p1, vector<int>& p2) {
        long long dx = p1[0] - p2[0];
        long long dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<long long> dists = {
            getDistSq(p1, p2),
            getDistSq(p1, p3),
            getDistSq(p1, p4),
            getDistSq(p2, p3),
            getDistSq(p2, p4),
            getDistSq(p3, p4)
        };
        
        sort(dists.begin(), dists.end());
        
        // dists[0] to dists[3] should be the 4 equal side lengths
        // dists[4] and dists[5] should be the 2 equal diagonal lengths
        return dists[0] > 0 && 
               dists[0] == dists[1] && 
               dists[1] == dists[2] && 
               dists[2] == dists[3] && 
               dists[4] == dists[5];
    }
};