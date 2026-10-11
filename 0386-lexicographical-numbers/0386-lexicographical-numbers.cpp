class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int current = 1;
        
        for (int i = 0; i < n; ++i) {
            result.push_back(current);
            
            // Try to go deeper into the Trie (multiply by 10)
            if (current * 10 <= n) {
                current *= 10;
            } 
            else {
                // If we can't go deeper or we exceed n, we backtrack
                while (current % 10 == 9 || current >= n) {
                    current /= 10;
                }
                // Move to the next sibling
                current += 1;
            }
        }
        
        return result;
    }
};