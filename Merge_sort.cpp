#include "header.h"

// function to merge two sorted parts in a array
void merge_sort(int *arr, int start_first, int end_first, int start_second, int end_second) {
    int first_ptr = start_first, second_ptr = start_second, size1 = end_first - start_first + 1, size2 = end_second - start_second + 1;
    int* sorted_array = new int[size1+size2];

    // sorts the array using two pointer approach
    for (int i = 0; i < size1 + size2; i++){
        if(first_ptr <= end_first && second_ptr <= end_second) {
            if(arr[first_ptr] > arr[second_ptr]){
                sorted_array[i] = arr[second_ptr++];
            } else {
                sorted_array[i] = arr[first_ptr++];
            }
        } else if (first_ptr <= end_first){
            sorted_array[i] = arr[first_ptr++];
        } else {
            sorted_array[i] = arr[second_ptr++];
        }
    }

    // replacing the values
    int index = 0;
    while(index < size1){
        arr[start_first + index] = sorted_array[index];
        index++;
    }

    index = 0;
    while(index < size2){
        arr[start_second + index] = sorted_array[size1 + index];
        index++;
    }

    // free the memory
    delete[] sorted_array; 
}

// function to divides the array and sends to join the sorted array
void merge(int *arr, int start, int end){
    if(start >= end) return;
    int mid = (start + end)/2;

    // divide the array
    merge(arr, start, mid);
    merge(arr, mid+1, end);

    // join the sorted arrays
    merge_sort(arr, start, mid, mid+1, end);
}

int main(){
    int arr[] = {32,4,5,7,6,43,45,2312,23,345,54,56,24};
    int size = sizeof(arr)/sizeof(arr[0]);
    int number = 6;

    cout<< "Before sorting" << endl;
    display_array(arr, size);
    merge(arr, 0, size-1);
    cout << "After sorting" << endl;
    display_array(arr, size);

    return 0;
}