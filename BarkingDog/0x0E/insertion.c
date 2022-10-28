#include <stdio.h>
void insertion_sort(int *arr, int size){
    int key;
    for(int i = 1; i < size; i++){
        key = arr[i];
        for(int j = i-1; j >= 0; j--){
            if(key < arr[j])
                arr[j+1] = arr[j];
            else break;
            arr[j] = key;
        }
    }
}
int main(void){
    int arr[] = {1,7,6,2,3,4,18,11,23,7};
    int size = sizeof(arr) / sizeof(int);
    insertion_sort(arr, size);
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
}