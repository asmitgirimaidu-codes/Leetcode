#include <string>
#include <vector>

class Solution {
private:
    std::string belowTen[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    std::string belowTwenty[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    std::string belowHundred[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    std::string helper(int num) {
        if (num == 0) {
            return "";
        } else if (num < 10) {
            return belowTen[num];
        } else if (num < 20) {
            return belowTwenty[num - 10];
        } else if (num < 100) {
            return belowHundred[num / 10] + (num % 10 != 0 ? " " + helper(num % 10) : "");
        } else {
            return belowTen[num / 100] + " Hundred" + (num % 100 != 0 ? " " + helper(num % 100) : "");
        }
    }

public:
    std::string numberToWords(int num) {
        if (num == 0) return "Zero";

        std::string result = "";
        
        if (num >= 1000000000) {
            result += helper(num / 1000000000) + " Billion";
            num %= 1000000000;
            if (num > 0) result += " ";
        }
        
        if (num >= 1000000) {
            result += helper(num / 1000000) + " Million";
            num %= 1000000;
            if (num > 0) result += " ";
        }
        
        if (num >= 1000) {
            result += helper(num / 1000) + " Thousand";
            num %= 1000;
            if (num > 0) result += " ";
        }
        
        if (num > 0) {
            result += helper(num);
        }

        return result;
    }
};