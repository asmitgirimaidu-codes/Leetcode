#include <string>
#include <algorithm>

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            int count = 0;
            string current = "";
            for (int j = i; j < n; ++j) {
                current += s[j];
                if (s[j] == '1') {
                    count++;
                }
                
                if (count == k) {
                    if (ans == "" || current.length() < ans.length() || 
                        (current.length() == ans.length() && current < ans)) {
                        ans = current;
                    }
                    break; // Since we want the shortest starting from index i, we can break early
                }
            }
        }
        
        return ans;
    }
};