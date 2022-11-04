#include <stdio.h>
void selection_sort(int *arr, int size){
    int min, min_idx, i, j;
    for(i = 0; i < size; i++){
        min = arr[i];
        min_idx = i;
        for(j = i+1; j < size; j++){
            if(min > arr[j]){
                min = arr[j];
                min_idx = j;
            }
        }
        arr[min_idx] = arr[i];
        arr[i] = min;
    }
}
int main(void){
    int arr[] = {1,7,6,2,3,4,18,11,23,7};
    int size = sizeof(arr) / sizeof(int);
    selection_sort(arr, size);
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
}