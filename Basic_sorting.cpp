#include "header.h"

void basic_sorting(int *arr, int size) {
    int sorted_array[size];

    for (int i = 0; i < size; i++)
    {
        int index = -1, smallest = INT_MAX;
        for(int j = 0; j < size; j++) {
            if(arr[j] < smallest) {
                smallest = arr[j];
                index = j;
            }
        }
        if(smallest != INT_MAX) {
            sorted_array[i] = smallest;
            arr[index] = INT_MAX;
        }
    }

    for (int i = 0; i < size; i++){
        arr[i] = sorted_array[i];
    }
}

int main(){
    int arr[] = {32,4,5,7,6,43,45,2312,23,345,54,56,24};
    int size = sizeof(arr)/sizeof(arr[0]);
    int number = 6;

    cout<< "Before sorting" << endl;
    display_array(arr, size);
    basic_sorting(arr, size);
    cout << "After sorting" << endl;
    display_array(arr, size);

    return 0;
}