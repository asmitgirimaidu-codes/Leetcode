class Solution {
    struct TrieNode {
        int children[26];
        int best_index;
        int min_len;
        
        TrieNode() {
            fill(children, children + 26, -1);
            best_index = -1;
            min_len = INT_MAX;
        }
    };
    
    vector<TrieNode> trie;
    
    void insert(int index, const string& s) {
        int curr = 0;
        int len = s.length();
        
        // Update root node if this string is better
        if (len < trie[curr].min_len) {
            trie[curr].min_len = len;
            trie[curr].best_index = index;
        }
        
        // Traverse and build Trie with reversed string
        for (int i = 0; i < len; i++) {
            int char_idx = s[i] - 'a';
            if (trie[curr].children[char_idx] == -1) {
                trie[curr].children[char_idx] = trie.size();
                trie.emplace_back();
            }
            curr = trie[curr].children[char_idx];
            
            // Update node with the best matching candidate
            if (len < trie[curr].min_len) {
                trie[curr].min_len = len;
                trie[curr].best_index = index;
            }
        }
    }
    
    int query(const string& s) {
        int curr = 0;
        int best = trie[curr].best_index;
        
        for (char c : s) {
            int char_idx = c - 'a';
            if (trie[curr].children[char_idx] == -1) {
                break; // No further common suffix
            }
            curr = trie[curr].children[char_idx];
            best = trie[curr].best_index;
        }
        return best;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.clear();
        trie.emplace_back(); // Root node
        
        // Step 1: Insert reversed words from wordsContainer into the Trie
        for (int i = 0; i < wordsContainer.size(); i++) {
            string rev = wordsContainer[i];
            reverse(rev.begin(), rev.end());
            insert(i, rev);
        }
        
        // Step 2: Answer queries using the reversed query strings
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& q : wordsQuery) {
            string rev_q = q;
            reverse(rev_q.begin(), rev_q.end());
            ans.push_back(query(rev_q));
        }
        
        return ans;
    }
};