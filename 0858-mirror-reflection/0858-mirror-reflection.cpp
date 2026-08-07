class Solution {
public:
    int mirrorReflection(int p, int q) {
        // Divide both p and q by their greatest common divisor to simplify
        while (p % 2 == 0 && q % 2 == 0) {
            p /= 2;
            q /= 2;
        }
        
        // p is even, q is odd -> Receptor 2
        if (p % 2 == 0 && q % 2 != 0) {
            return 2;
        }
        // p is odd, q is odd -> Receptor 1
        if (p % 2 != 0 && q % 2 != 0) {
            return 1;
        }
        // p is odd, q is even -> Receptor 0
        if (p % 2 != 0 && q % 2 == 0) {
            return 0;
        }
        
        return 0;
    }
};