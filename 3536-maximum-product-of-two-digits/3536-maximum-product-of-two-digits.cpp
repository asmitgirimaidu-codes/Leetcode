class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        int len = s.length();
        
        // Convert the two largest character digits back to integers and multiply
        int digit1 = s[len - 1] - '0';
        int digit2 = s[len - 2] - '0';
        
        return digit1 * digit2;
    }
};