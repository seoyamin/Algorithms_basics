#include <stdio.h>

void shellSort(int arr[], int len) {
    
    for(int h=len/2 ; h>0 ; h/=2) {
        
        for(int i=0 ; i<h ; i++) {
            
            for(int j=h+i ; j<len ; j+=h) {   // i번째 그룹 삽입정렬 현재 주자 temp = arr[j] 
                int temp = arr[j];            // temp는 i번째 그룹의 index = 1인 2nd 원소 (원래 삽입 정렬은 index = 1 부터가 첫번째 주자)
                int idx = j;            
                
                
                // 하극상인 애 나올때까지 현재 주자 바로 앞 부분을 h간격으로 하나씩 살펴보기
                // 하극상 발견되면 현재 주자랑 하극상 자리 바꾸기 (삽입)
                // 바꾸고 나서도 바로 앞 부분을 h간격으로 살펴보며 또 하극상인 애 있는지 확인 후 반복
                while(arr[idx-h] > temp && idx >= h) {   
                    arr[idx] = arr[idx-h];    
                    idx -= h;
                }
                
                arr[idx] = temp;
            }
        }
    }
    
    for(int i=0 ; i<len ; i++) {
        printf("%d ", arr[i]);
    }
}


int main() {
    int arr[] = {30, 60, 90, 10, 40, 80, 40, 20, 10, 60, 50, 30, 40, 90, 80};
    int len = sizeof(arr) / sizeof(int);
    
    shellSort(arr, len);
    
    return 0;
}