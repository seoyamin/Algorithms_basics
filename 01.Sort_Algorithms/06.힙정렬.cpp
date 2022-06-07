#include <stdio.h>

typedef struct {
    int heap[100];
    int heapSize;
} HeapType;


void initHeap(HeapType *H) {
    H->heapSize = 0;
}


// insertHeap에서 key값을 H 맨 끝에 일단 넣어놓고, 진짜 key 자리 찾는 메소드
void upHeap(HeapType *H) {
    
    int i = H->heapSize;
    int key = H->heap[i];  // [맨 바닥에서 시작] key는 H의 맨 끝 마지막 원소 
    
    
    /* key에서부터 위로(parent로) 올라가면서 key가 더 크면 
    key값을 parent node에 대입하며 1칸 밀어냄 */
    while((i != 1) && (key > H->heap[i/2])) {  // heap[i/2] : key의 parent node
        H->heap[i] = H->heap[i/2];  // parent값을 child에 대입하면서 자리 비우고, 채우면서 올라감
        i /= 2;
    }
    
    H->heap[i] = key; // 알맞는 진짜 자리에 key값 대입
}



// heapSort에서 root 값을 알맞는 자리로 옮기는 메소드
void downHeap(HeapType *H) {
    int root = H->heap[1];      // [맨 꼭대기에서 시작]
    int parent = 1, child = 2;
    
    while(child <= H->heapSize) {    // 자리 찾을때까지 바닥 끝까지 내려갈 생각
        
        // right child 존재하면서 left < right이면 right를 child로 선택
        if((child < H->heapSize) && (H->heap[child+1] > H->heap[child])) {
            child++;
        }
        
        // root 값의 알맞은 자리 찾으면 break
        if(root >= H->heap[child]) {
            break;
        }
        
        // child 값을 parent에 대입하면서 자리 비우고, 채우면서 내려감   
        H->heap[parent] = H->heap[child];
        parent = child;
        child *= 2;
    }
    
    H->heap[parent] = root; // max heap 조건 만족하는 자리에 root값 대입 
}



void insertHeap(HeapType *H, int key) {
    H->heapSize++;
    H->heap[H->heapSize] = key;
    upHeap(H);
}



void heapSort(HeapType *H) {
    int n = H->heapSize;
    
    for(int i=1 ; i<=n ; i++) {
        
        // root heap[1]과 마지막 원소 heap[heapSize] 자리 바꾸기
        int temp = H->heap[1];
        H->heap[1] = H->heap[H->heapSize];
        H->heap[H->heapSize] = temp;
        
        // heap 크기 줄이기
        H->heapSize--;
        
        downHeap(H);
        
        printf("Step %d : ", i);
        for(int i=1 ; i<=n ; i++) {
            printf("(%d) ", H->heap[i]);
        }
        printf("\n");
    }
}



void printHeap(HeapType *H) {
    for(int i=1 ; i<=H->heapSize ; i++) {
        printf("(%d) ", H->heap[i]);
    }
    printf("\n");
}





int main() {
    HeapType H;
    initHeap(&H);
    
    insertHeap(&H, 90); insertHeap(&H, 60); insertHeap(&H, 80); 
    insertHeap(&H, 50); insertHeap(&H, 30); insertHeap(&H, 70); 
    insertHeap(&H, 10); insertHeap(&H, 20); insertHeap(&H, 40); 
    
    printHeap(&H);
    
    heapSort(&H);

    return 0;
}