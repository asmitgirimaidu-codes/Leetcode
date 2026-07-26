class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for (const string& word : words) {
            long long totalWeight = 0;
            for (char c : word) {
                totalWeight += weights[c - 'a'];
            }
            int rem = totalWeight % 26;
            char mappedChar = 'z' - rem;
            result += mappedChar;
        }
        return result;
    }
};