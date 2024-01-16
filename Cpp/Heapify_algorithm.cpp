#include "header.h"

void heapifyTheIndex(int arr[], int size, int index) {
    int largest = index;
    int left = 2*index; // left part of the node
    int right = 2*index + 1; // right part of the node

    // check the left part is larger or not
    if(left < size && arr[left] > arr[largest]) { largest = left; }

    // check the left part is larger or not
    if(right < size && arr[right] > arr[largest]) { largest = right; }

    // if their is larger value in left or right part then swap with it and heapify the nodes on that subtree part
    if(largest != index) {
        swap(arr[largest], arr[index]);
        heapifyTheIndex(arr, size, largest);
    }
}

void heapify(int arr[], int size){
    // create a new array to make heap from it
    int* newArr = new int[size+1];
    
    newArr[0] = -1;

    // copy the data into new array
    for (int i = 1; i <= size; i++) { newArr[i] = arr[i-1]; }

    // heapify the new array
    for (int i = size/2; i > 0; i--) { heapifyTheIndex(newArr, size+1, i); }

    // copy back the heapified array to original array
    for (int i = 1; i <= size; i++) { arr[i-1] = newArr[i]; }
}


int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    display_array(arr, size);
    heapify(arr, size);
    display_array(arr, size);

    return 0;
}