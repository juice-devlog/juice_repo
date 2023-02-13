#include <stdio.h>

void merge(int *arr, int p, int q, int r){
    int i = p, j = q+1, k = p;
    int tmp[r];
    while(i <= q && j <= r){
        if(arr[i] < arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    while(i <= q) tmp[k++] = arr[i++];
    while(j <= r) tmp[k++] = arr[j++];
    for(int idx = p; idx <= r; idx++) arr[idx] = tmp[idx];
}
void merge_sort(int *arr, int p, int r){
    int q;
    if(p < r){
        q = (p+r)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main(void){
    int arr[] = {1,7,6,2,3,4,18,11,23,7};
    int size = sizeof(arr) / sizeof(int);
    merge_sort(arr, 0, size);
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
}