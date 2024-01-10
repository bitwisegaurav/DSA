#include "header.h"

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1])
                swap_numbers(&arr[j], &arr[j+1]);
            // display_array(arr, size); // uncomment this to see the iterations
        }
    }
}

int main(){
    int arr[] = {32,4,5,7,6,43,45,2312,23,345,54,56,24};
    int size = sizeof(arr)/sizeof(arr[0]);
    int number = 6;

    cout<< "Before sorting" << endl;
    display_array(arr, size);
    bubble_sort(arr, size);
    cout << "After sorting" << endl;
    display_array(arr, size);

    return 0;
}