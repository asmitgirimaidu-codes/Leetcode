/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        // Step 1: Find the peak index of the mountain array
        int left = 0, right = n - 1;
        int peak = 0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = peak = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // Step 2: Binary search on the strictly increasing left side
        left = 0;
        right = peak;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Step 3: Binary search on the strictly decreasing right side
        left = peak;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val < target) {
                // Since the right side is decreasing, a smaller value means we need to go left
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return -1; // Target not found
    }
};