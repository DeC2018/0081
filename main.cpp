#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            const int m = (l + r) / 2; // Calculate the middle index
            if (nums[m] == target) // If the middle element is the target
                return true;

            // Handle duplicates by shrinking the search space
            if (nums[l] == nums[m] && nums[m] == nums[r]) {
                ++l;
                --r;
            } else if (nums[l] <= nums[m]) { // Left half is sorted
                if (nums[l] <= target && target < nums[m]) // Target is in the left half
                    r = m - 1;
                else // Target is in the right half
                    l = m + 1;
            } else { // Right half is sorted
                if (nums[m] < target && target <= nums[r]) // Target is in the right half
                    l = m + 1;
                else // Target is in the left half
                    r = m - 1;
            }
        }

        return false; // Target not found
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    cout << "Input: nums = [2,5,6,0,0,1,2], target = " << target1 << endl;
    cout << "Output: " << (solution.search(nums1, target1) ? "true" : "false") << endl;

    vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    cout << "Input: nums = [2,5,6,0,0,1,2], target = " << target2 << endl;
    cout << "Output: " << (solution.search(nums2, target2) ? "true" : "false") << endl;

    return 0;
}
