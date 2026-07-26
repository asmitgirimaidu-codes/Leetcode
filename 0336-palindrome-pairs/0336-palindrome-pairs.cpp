class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> word_to_idx;
        for (int i = 0; i < words.size(); ++i) {
            string w = words[i];
            reverse(w.begin(), w.end());
            word_to_idx[w] = i;
        }

        vector<vector<int>> result;

        for (int i = 0; i < words.size(); ++i) {
            string w = words[i];
            
            for (int j = 0; j <= w.length(); ++j) {
                string left = w.substr(0, j);
                string right = w.substr(j);

                // If left is a palindrome, check if reverse(right) exists in words
                if (isPalindrome(left)) {
                    auto it = word_to_idx.find(right);
                    if (it != word_to_idx.end() && it->second != i) {
                        result.push_back({it->second, i});
                    }
                }

                // If right is a palindrome, check if reverse(left) exists in words
                // Avoid duplicate pairs by checking j < w.length() when right is empty
                if (j < w.length() && isPalindrome(right)) {
                    auto it = word_to_idx.find(left);
                    if (it != word_to_idx.end() && it->second != i) {
                        result.push_back({i, it->second});
                    }
                }
            }
        }

        return result;
    }

private:
    bool isPalindrome(const string& s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};