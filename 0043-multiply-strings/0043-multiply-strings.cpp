#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n = num1.size(), m = num2.size();
        // The result of multiplying two numbers of size n and m 
        // will have at most n + m digits.
        vector<int> pos(n + m, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + pos[p2];
                
                pos[p1] += sum / 10;
                pos[p2] = sum % 10;
            }
        }
        
        string res = "";
        for (int p : pos) {
            if (!(res.empty() && p == 0)) {
                res.push_back(p + '0');
            }
        }
        
        return res.empty() ? "0" : res;
    }
};