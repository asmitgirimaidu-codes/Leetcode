#include <vector>
#include <string>
#include <deque>

class StreamChecker {
private:
    struct TrieNode {
        bool isEnd;
        TrieNode* children[26];
        TrieNode() : isEnd(false) {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    TrieNode* root;
    std::deque<char> stream;

    void insert(const std::string& word) {
        TrieNode* curr = root;
        for (int i = word.length() - 1; i >= 0; i--) {
            int idx = word[i] - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

public:
    StreamChecker(std::vector<std::string>& words) {
        root = new TrieNode();
        for (const std::string& word : words) {
            insert(word);
        }
    }
    
    bool query(char letter) {
        stream.push_front(letter);
        TrieNode* curr = root;
        
        for (char ch : stream) {
            int idx = ch - 'a';
            if (!curr->children[idx]) {
                break;
            }
            curr = curr->children[idx];
            if (curr->isEnd) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */