#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
private:
    // Union-Find (Disjoint Set) structure
    std::unordered_map<string, string> parent;

    string find(string s) {
        if (parent[s] != s) {
            parent[s] = find(parent[s]); // Path compression
        }
        return parent[s];
    }

    void unite(string s1, string s2) {
        string root1 = find(s1);
        string root2 = find(s2);
        if (root1 != root2) {
            parent[root2] = root1;
        }
    }

public:
    std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) {
        std::unordered_map<string, string> emailToName;

        // Step 1: Initialize Union-Find and map each email to its account name
        for (const auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                string email = account[i];
                if (parent.find(email) == parent.end()) {
                    parent[email] = email;
                }
                emailToName[email] = name;
                // Union all emails in the same account with the first email
                unite(account[1], email);
            }
        }

        // Step 2: Group emails by their root parent
        std::unordered_map<string, std::vector<string>> component;
        for (const auto& pair : parent) {
            string email = pair.first;
            string root = find(email);
            component[root].push_back(email);
        }

        // Step 3: Format the final output
        std::vector<std::vector<std::string>> res;
        for (auto& pair : component) {
            string root = pair.first;
            auto& emails = pair.second;
            
            // Sort emails lexicographically
            std::sort(emails.begin(), emails.end());
            
            std::vector<std::string> mergedAccount;
            mergedAccount.push_back(emailToName[root]); // Add the name
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end()); // Add sorted emails
            
            res.push_back(mergedAccount);
        }

        return res;
    }
};