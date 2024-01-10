#include "header.h"

void selection_sort(int *arr, int size) {
    for (int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++) {
            if(arr[i] > arr[j])
                swap_numbers(&arr[i], &arr[j]);
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
    selection_sort(arr, size);
    cout << "After sorting" << endl;
    display_array(arr, size);

    return 0;
}