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

void heap_sort(int arr[], int size) {
    int index = size;

    while(index > 0) {
        // swap the largest element with the last element
        swap(arr[0], arr[index-1]);
        // reduce the size of the heap by one
        index--;
        // heapify the new heap
        heapifyTheIndex(arr, index, 0);
    }
}

int main() {
    int arr[] = {12,45,43,67,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array : ";
    display_array(arr, size);
    cout << "Heapified array : ";
    heapify(arr, size);
    display_array(arr, size);
    cout << "Sorted array : ";
    heap_sort(arr, size);
    display_array(arr, size);

    return 0;
}