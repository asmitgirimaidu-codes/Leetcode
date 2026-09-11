class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }
        
        int uniqueEvenCount = 0;
        
        // Iterate through all 3-digit even numbers
        for (int num = 100; num < 1000; num += 2) {
            int hundreds = num / 100;
            int tens = (num / 10) % 10;
            int units = num % 10;
            
            vector<int> tempCount(10, 0);
            tempCount[hundreds]++;
            tempCount[tens]++;
            tempCount[units]++;
            
            bool possible = true;
            for (int i = 0; i < 10; ++i) {
                if (tempCount[i] > count[i]) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                uniqueEvenCount++;
            }
        }
        
        return uniqueEvenCount;
    }
};