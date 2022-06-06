#include <stdio.h>

void quickSort(int arr[], int start, int end) {
    int temp; 
    
    // 원소 1개인 경우
    if(start >= end) {  
        return;
    }
    
    int key = start;
    int left = start + 1;
    int right = end;
    
    while(left <= right) {    // left와 right (index) 엇갈릴때까지 반복
        while(arr[left] <= arr[key]) {
            left++;
        }
        
        while(arr[right] >= arr[key] && right > start) {
            right--;
        }
        
        if(left > right) {    // left와 right 엇갈린 경우 : left와 key 자리바꾸기 (while문 break)
            temp = arr[right];
            arr[right] = arr[key];
            arr[key] = temp;
        }
        
        else {                // left와 right 엇갈리지 않은 경우 : left와 right 자리 바꾸기 (while문 계속)
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    
    quickSort(arr, start, right-1);
    quickSort(arr, right+1, end);
    
    
}


int main() {
    int arr[] = {40, 10, 50, 90, 20, 80, 30, 60};
    int len = sizeof(arr) / sizeof(int);
    
    quickSort(arr, 0, len-1);
    
    for(int i=0 ; i<len ; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}