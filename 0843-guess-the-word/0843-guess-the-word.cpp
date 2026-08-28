class Solution {
public:
    // Helper function to count matching characters and positions between two words
    int getMatches(const string& w1, const string& w2) {
        int matches = 0;
        for (int i = 0; i < 6; ++i) {
            if (w1[i] == w2[i]) {
                matches++;
            }
        }
        return matches;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> candidates = words;
        
        for (int i = 0; i < 30; ++i) {
            if (candidates.empty()) break;

            // Step 1: Find the best word to guess using the minimax strategy
            string bestWord = candidates[0];
            int minMaxGroupSize = INT_MAX;

            for (const string& w1 : candidates) {
                // Count how many words fall into each match count category (0 to 6)
                vector<int> matchCounts(7, 0);
                for (const string& w2 : candidates) {
                    matchCounts[getMatches(w1, w2)]++;
                }

                // Find the maximum group size for this candidate
                int maxGroupSize = 0;
                for (int count : matchCounts) {
                    maxGroupSize = max(maxGroupSize, count);
                }

                // We want to minimize the maximum remaining candidates
                if (maxGroupSize < minMaxGroupSize) {
                    minMaxGroupSize = maxGroupSize;
                    bestWord = w1;
                }
            }

            // Step 2: Make the guess using Master API
            int matches = master.guess(bestWord);
            if (matches == 6) {
                return; // Found the secret word!
            }

            // Step 3: Filter candidates that match the feedback from Master
            vector<string> nextCandidates;
            for (const string& w : candidates) {
                if (getMatches(bestWord, w) == matches) {
                    nextCandidates.push_back(w);
                }
            }
            candidates = move(nextCandidates);
        }
    }
};