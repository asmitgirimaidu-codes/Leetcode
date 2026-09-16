class Solution {
public:
    int flipLights(int n, int presses) {
        if (presses == 0) return 1;
        
        if (n == 1) {
            return 2; // States: all on, all off
        } else if (n == 2) {
            // With presses >= 3, we can reach 4 states. With presses == 1, 3 states. With presses == 2, 4 states.
            return presses == 1 ? 3 : 4;
        } else {
            // For n >= 3:
            if (presses == 1) return 4;
            if (presses == 2) return 7;
            return 8; // presses >= 3 yields at most 8 distinct states
        }
    }
};