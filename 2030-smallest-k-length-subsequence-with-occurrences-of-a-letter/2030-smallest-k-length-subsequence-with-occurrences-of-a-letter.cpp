#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string smallestSubsequence(std::string s, int k, char letter, int repetition) {
        int total_letter_count = 0;
        for (char c : s) {
            if (c == letter) {
                total_letter_count++;
            }
        }

        std::string stack = "";
        int current_letter_in_stack = 0;
        int remaining_letters_to_process = total_letter_count;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            // Pop elements from the stack if:
            // 1. Stack is not empty and top element is greater than current character.
            // 2. We can still form a string of length k with the remaining characters.
            // 3. If we pop the target letter, we must ensure we still have enough target 
            //    letters left (both in stack and remaining in string) to meet the required repetition.
            while (!stack.empty() && stack.back() > c && 
                   (stack.length() + s.length() - i - 1 >= k) && 
                   (stack.back() != letter || current_letter_in_stack + remaining_letters_to_process - 1 >= repetition)) {
                
                if (stack.back() == letter) {
                    current_letter_in_stack--;
                }
                stack.pop_back();
            }

            // Push character to stack if:
            // 1. We haven't reached length k yet.
            // 2. If current character is the target letter, we can push it as long as we don't exceed k.
            // 3. If current character is NOT the target letter, we can only push it if the remaining 
            //    slots (k - stack.length() - 1) are enough to accommodate all needed target letter repetitions.
            int remaining_slots = k - stack.length();
            if (remaining_slots > 0) {
                if (c == letter) {
                    stack.push_back(c);
                    current_letter_in_stack++;
                } else {
                    // Check if we still have enough room to fit the required remaining repetitions
                    int needed_repetitions = repetition - current_letter_in_stack;
                    if (remaining_slots - 1 >= needed_repetitions) {
                        stack.push_back(c);
                    }
                }
            }

            if (c == letter) {
                remaining_letters_to_process--;
            }
        }

        return stack;
    }
};