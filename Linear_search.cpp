// This file for running the code so that there will be only one file which will be compiled
#include "header.h"

bool linear_search(int arr[], int size, int number){
    for (int i = 0; i < size; i++) {
        if(arr[i] == number) return true;
    }
    return false;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int number = 6;

    string ans = linear_search(arr, size, number) ? "It is present" : "It is not present";
    
    cout << ans << endl;

    return 0;
}