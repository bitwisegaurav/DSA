#include "header.h"

bool binary_search(int arr[], int size, int number){
    int start = 0, end = size-1;

    while (start<end){
        if(arr[start] == number || arr[end] == number) return true;
        int mid = end + (start - end)/2;

        if(arr[mid] == number) return true;
        else if(arr[mid] > number) end = mid - 1;
        else start = mid + 1;
    }

    return false;
}

int main(){
    int arr[] = {0,1,2,3,4,5,6,7,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int number = 6;

    string ans = binary_search(arr, size, number) ? "It is present" : "It is not present";
    
    cout << ans << endl;

    return 0;
}