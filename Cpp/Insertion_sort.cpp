#include "header.h"

void shift_numbers(int *arr, int start, int end){
    for(int i = end; i>start; i--)
        arr[i] = arr[i-1];
}

void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++){
        for(int j = 0; j < i; j++) {
            if(arr[i] < arr[j]){
                // Shift numbers to the right of the greater number
                int temp = arr[i];
                shift_numbers(arr, j, i);
                arr[j] = temp;
                break;
            }
            // display_array(arr, size); // uncomment this to see the iterations
        }
    }
}

int main(){
    int arr[] = {32,4,5,7,6,43,45,2312,23,345,54,56,24};
    // 32, 4, 5, 7,7, 6,43,45,23,345,54,56,24
    // int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int number = 6;

    cout<< "Before sorting" << endl;
    display_array(arr, size);
    insertion_sort(arr, size);
    cout << "After sorting" << endl;
    display_array(arr, size);

    return 0;
}