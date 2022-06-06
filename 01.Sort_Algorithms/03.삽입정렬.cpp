#include <stdio.h>

void insertionSort(int arr[], int len) {
    int temp; 
    
    for(int i=1 ; i<len ; i++) {
        // int j = i;
        // while(arr[j] < arr[j-1]) {
        //     temp = arr[j];
        //     arr[j] = arr[j-1];
        //     arr[j-1] = temp;
        //     j--;
        // }
        
        for(int j = i ; j > 0 ; j--) {
            if(arr[j] < arr[j-1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
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
    
    insertionSort(arr, len);
    
    return 0;
}