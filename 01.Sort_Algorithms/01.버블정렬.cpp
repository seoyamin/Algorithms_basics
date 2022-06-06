#include <stdio.h>

void bubbleSort(int arr[], int len) {
    int temp = 0; 
    
    for(int i=0 ; i<len ; i++) {
        for(int j=0 ; j<len-i ; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for(int i=0 ; i<len ; i++) {
        printf("%d ", arr[i]);
    }
}


int main() {
    int arr[] = {40, 10, 50, 90, 20, 80, 30, 60};
    int len = sizeof(arr) / sizeof(int);
    
    bubbleSort(arr, len);
    
    return 0;
}