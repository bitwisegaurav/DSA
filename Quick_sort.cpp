#include "header.h"

int sort(int* arr, int end, int start = 0){
    if (start >= end) return start;

    int pivot = start;

    // count numbers less than arr[start]
    int count = 0;
    for (int i = start; i <= end; i++){
        if(i != pivot && arr[i] < arr[pivot]) count++;
    }

    pivot = start + count;

    swap_numbers(&arr[start], &arr[pivot]);

    int end_ptr = end;

    // separating small and large numbers
    for(int i=start; i<pivot; i++){
        if(arr[i] > arr[pivot]){
            while(arr[end_ptr] >= arr[pivot]) end_ptr--;
            swap_numbers(&arr[i], &arr[end_ptr]);
        }
    }

    return pivot;
}

void quick_sort(int *arr, int end, int start = 0){
    if(start >= end) return;

    int partition = sort(arr, end, start);

    quick_sort(arr, partition - 1, start);
    quick_sort(arr, end, partition + 1);
}

int main(){
    int arr[] = {32,4,5,7,6,43,45,2312,23,345,54,56,24};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout<< "Before sorting" << endl;
    display_array(arr, size);
    quick_sort(arr, size-1);
    cout << "After sorting" << endl;
    display_array(arr, size);

    return 0;
}