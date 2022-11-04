#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void quick_sort(int *arr, int st, int en){
    if(en <= st+1) return;
    int key = arr[st];
    int l = st+1;
    int r = en-1;
    while(1){
        while(l <= r && arr[l] <= key) l++;
        while(l <= r && arr[r] > key) r--;
        if(l > r) break;
        swap(&arr[l], &arr[r]);
    }
    swap(&arr[st], &arr[r]);
    quick_sort(arr, st, r);
    quick_sort(arr, r+1, en);
}
int main(void){
    int arr[] = {1,7,6,2,3,4,18,11,23,7};
    int size = sizeof(arr) / sizeof(int);
    quick_sort(arr, 0, size);
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
}