#include <stdio.h>
void bubble_sort(int *arr, int size){
    int temp;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - (i+1); j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(void){
    int arr[] = {1,7,6,2,3,4,18,11,23,7};
    int size = sizeof(arr) / sizeof(int);
    bubble_sort(arr, size);
    for(int i = 0; i < size; i++) printf("%d, ", arr[i]);
}