class Solution {
private:
    int memo[20][20];

    int solve(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        if (memo[l][r] != -1) {
            return memo[l][r];
        }
        int pickLeft = nums[l] - solve(nums, l + 1, r);
        int pickRight = nums[r] - solve(nums, l, r - 1);
        return memo[l][r] = max(pickLeft, pickRight);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(memo, -1, sizeof(memo));
        return solve(nums, 0, n - 1) >= 0;
    }
};