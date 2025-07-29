#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return 1;
    }
    
    int* unique = (int*)malloc(numsSize * sizeof(int));
    int uniqueCount = 1; 
    unique[0] = nums[0]; 
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != unique[uniqueCount - 1]) {
            unique[uniqueCount] = nums[i];
            uniqueCount++;
        }
    }
    
    for (int i = 0; i < uniqueCount; i++) {
        nums[i] = unique[i];
    }
    

    free(unique);
    
    return uniqueCount;
}


void printArray(int* nums, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i > 0) printf(",");
        printf("%d", nums[i]);
    }
    printf("]\n");
}

int main() {
    int nums1[] = {1, 1, 2};
    int size1 = 3;
    int result1 = removeDuplicates(nums1, size1);
    printf("Test 1: %d, nums = ", result1);
    printArray(nums1, result1);
    
    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size2 = 10;
    int result2 = removeDuplicates(nums2, size2);
    printf("Test 2: %d, nums = ", result2);
    printArray(nums2, result2);
    
    return 0;
}