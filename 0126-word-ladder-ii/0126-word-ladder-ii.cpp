class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        unordered_map<string, int> mpp;
        queue<string> q;
        
        q.push(beginWord);
        mpp[beginWord] = 0;
        dict.erase(beginWord);
        
        int L = beginWord.length();
        bool found = false;
        
        // BFS to find the shortest distance from beginWord to every reachable word
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            
            if (word == endWord) {
                found = true;
                break;
            }
            
            int steps = mpp[word];
            string original = word;
            
            for (int i = 0; i < L; ++i) {
                char originalChar = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    if (dict.count(word)) {
                        q.push(word);
                        dict.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = originalChar;
            }
        }
        
        if (!found) return ans;
        
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, path, mpp, ans);
        
        return ans;
    }
    
private:
    void dfs(string word, const string& beginWord, vector<string>& path, unordered_map<string, int>& mpp, vector<vector<string>>& ans) {
        if (word == beginWord) {
            vector<string> revPath = path;
            reverse(revPath.begin(), revPath.end());
            ans.push_back(revPath);
            return;
        }
        
        int steps = mpp[word];
        int L = word.length();
        string original = word;
        
        for (int i = 0; i < L; ++i) {
            char originalChar = word[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                word[i] = c;
                if (mpp.count(word) && mpp[word] == steps - 1) {
                    path.push_back(word);
                    dfs(word, beginWord, path, mpp, ans);
                    path.pop_back();
                }
            }
            word[i] = originalChar;
        }
    }
};