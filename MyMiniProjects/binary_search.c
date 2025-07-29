#include <stdio.h>


int binary_search(int *arr, int size, int target){
    int left = 0;
    int right = size - 1;

    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == target){
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}


int main(){
    int numbers[] = {1, 4, 7, 15, 18, 26, 33, 48, 75, 86};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 33;

    int result = binary_search(numbers, size, target);
    printf("%d \n", result);

    return 0;
}