#include <stdio.h>
#include <stdbool.h>

bool search(int* nums, int numsSize, int target) {
    int start = 0, end = numsSize - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (target == nums[mid]) return true;

        if (nums[start] == nums[mid]) {
            start++;
            continue;
        } else if (nums[mid] <= nums[end]) { // Right half is sorted
            if (target >= nums[mid] && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        } else { // Left half is sorted
            if (target >= nums[start] && target <= nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return false;
}

int main() {
    int nums1[] = {2, 5, 6, 0, 0, 1, 2};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int target1 = 0;
    printf("Input: nums = [2,5,6,0,0,1,2], target = %d\n", target1);
    printf("Output: %s\n", search(nums1, numsSize1, target1) ? "true" : "false");

    int nums2[] = {2, 5, 6, 0, 0, 1, 2};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int target2 = 3;
    printf("Input: nums = [2,5,6,0,0,1,2], target = %d\n", target2);
    printf("Output: %s\n", search(nums2, numsSize2, target2) ? "true" : "false");

    return 0;
}
