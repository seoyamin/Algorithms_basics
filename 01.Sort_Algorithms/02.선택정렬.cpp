#include <stdio.h>

void selectSort(int arr[], int len) {
    int temp; 
    
    for(int i=0 ; i<len ; i++) {
        int minIdx = i;
        
        for(int j=i ; j<len ; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
    
    for(int i=0 ; i<len ; i++) {
        printf("%d ", arr[i]);
    }
}


int main() {
    int arr[] = {40, 10, 50, 90, 20, 80, 30, 60};
    int len = sizeof(arr) / sizeof(int);
    
    selectSort(arr, len);
    
    return 0;
}