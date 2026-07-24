#include <string>
#include <vector>

class Trie {
private:
    struct TrieNode {
        bool isEnd = false;
        TrieNode* children[26] = {nullptr};
    };
    
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(std::string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(std::string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(std::string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */