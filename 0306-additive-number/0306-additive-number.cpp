#include <string>
#include <algorithm>

class Solution {
private:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            carry = sum / 10;
            res += to_string(sum % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isValid(string n1, string n2, string remain) {
        string sumStr = addStrings(n1, n2);
        if (remain.find(sumStr) != 0) return false;
        if (remain == sumStr) return true;
        return isValid(n2, sumStr, remain.substr(sumStr.length()));
    }

public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        if (n < 3) return false;

        for (int i = 1; i <= n / 2; ++i) {
            if (num[0] == '0' && i > 1) break; // First number cannot have leading zeros
            string n1 = num.substr(0, i);
            
            for (int j = 1; n - i - j >= max(i, j); ++j) {
                if (num[i] == '0' && j > 1) break; // Second number cannot have leading zeros
                string n2 = num.substr(i, j);
                
                string remain = num.substr(i + j);
                if (isValid(n1, n2, remain)) return true;
            }
        }
        return false;
    }
};