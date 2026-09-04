#include <string>
#include <string_view>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.length();
        int left = 1, right = n - 1;
        int start = -1;
        int maxLength = 0;

        // Base and moduli for double rolling hashing to prevent collisions
        long long mod1 = 2147483647; // A large prime
        long long mod2 = 1000000007; // Another large prime
        long long base = 31;

        // Helper lambda to check if a duplicate of length L exists using Rabin-Karp
        auto search = [&](int L) -> int {
            if (L == 0) return 0;
            
            long long h1 = 0, h2 = 0;
            long long power1 = 1, power2 = 1;

            for (int i = 0; i < L; ++i) {
                h1 = (h1 * base + (s[i] - 'a' + 1)) % mod1;
                h2 = (h2 * base + (s[i] - 'a' + 1)) % mod2;
                if (i < L - 1) {
                    power1 = (power1 * base) % mod1;
                    power2 = (power2 * base) % mod2;
                }
            }

            // Store combined hashes as a 64-bit integer
            unordered_set<long long> seen;
            seen.insert((h1 << 32) | h2);

            for (int i = 1; i <= n - L; ++i) {
                h1 = (h1 - (s[i - 1] - 'a' + 1) * power1 % mod1 + mod1) % mod1;
                h1 = (h1 * base + (s[i + L - 1] - 'a' + 1)) % mod1;

                h2 = (h2 - (s[i - 1] - 'a' + 1) * power2 % mod2 + mod2) % mod2;
                h2 = (h2 * base + (s[i + L - 1] - 'a' + 1)) % mod2;

                long long hash_pair = (h1 << 32) | h2;
                if (seen.count(hash_pair)) {
                    return i; // Returns the starting index of the duplicated substring
                }
                seen.insert(hash_pair);
            }
            return -1;
        };

        // Binary search over the possible length of the duplicate substring
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int idx = search(mid);
            if (idx != -1) {
                start = idx;
                maxLength = mid;
                left = mid + 1; // Try to find a longer duplicate
            } else {
                right = mid - 1; // Too long, try shorter lengths
            }
        }

        return maxLength == 0 ? "" : s.substr(start, maxLength);
    }
};