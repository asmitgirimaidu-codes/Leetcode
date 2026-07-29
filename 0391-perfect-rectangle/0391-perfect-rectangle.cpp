class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> corners;
        long long totalArea = 0;
        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;

        for (const auto& rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            
            // Update bounding rectangle coordinates
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            // Add to total area
            totalArea += (long long)(x2 - x1) * (y2 - y1);

            // Process the 4 corners of the current rectangle
            string c1 = to_string(x1) + "," + to_string(y1);
            string c2 = to_string(x1) + "," + to_string(y2);
            string c3 = to_string(x2) + "," + to_string(y1);
            string c4 = to_string(x2) + "," + to_string(y2);

            // Toggle corners in the set (insert if not present, erase if already present)
            for (const string& c : {c1, c2, c3, c4}) {
                if (corners.count(c)) {
                    corners.erase(c);
                } else {
                    corners.insert(c);
                }
            }
        }

        // The only remaining corners in the set should be the exact 4 corners of the large bounding rectangle
        string b1 = to_string(minX) + "," + to_string(minY);
        string b2 = to_string(minX) + "," + to_string(maxY);
        string b3 = to_string(maxX) + "," + to_string(minY);
        string b4 = to_string(maxX) + "," + to_string(maxY);

        if (corners.size() != 4 || !corners.count(b1) || !corners.count(b2) || !corners.count(b3) || !corners.count(b4)) {
            return false;
        }

        // Check if the sum of areas of all small rectangles equals the area of the bounding rectangle
        long long expectedArea = (long long)(maxX - minX) * (maxY - minY);
        return totalArea == expectedArea;
    }
};