#include "header.h"

void heapifyTheIndex(int arr[], int size, int index) {
    int largest = index;
    int left = 2*index + 1; // left part of the node
    int right = 2*index + 2; // right part of the node

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
    // heapify the new array
    for (int i = size/2 - 1; i >= 0; i--) { heapifyTheIndex(arr, size, i); }
}


int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    display_array(arr, size);
    heapify(arr, size);
    display_array(arr, size);

    return 0;
}