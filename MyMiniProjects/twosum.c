#include <stdio.h>

void twoSum(int nums[], int size, int target, int result[]) {
    for (int i = 0; i < size - 1; i++) { 
        for (int j = i + 1; j < size; j++) { 
            if (nums[i] + nums[j] == target) {
                result[0] = i; 
                result[1] = j; 
                return; 
            }
        }
    }
}

int main() {
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int result1[2];
    twoSum(nums1, 4, target1, result1);
    printf("Example 1: [%d, %d]\n", result1[0], result1[1]); 

    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int result2[2];
    twoSum(nums2, 3, target2, result2);
    printf("Example 2: [%d, %d]\n", result2[0], result2[1]); 
    
    int nums3[] = {3, 3};
    int target3 = 6;
    int result3[2];
    twoSum(nums3, 2, target3, result3);
    printf("Example 3: [%d, %d]\n", result3[0], result3[1]); 

    return 0;
}