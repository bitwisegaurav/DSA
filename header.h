// This file is for adding/including all the important header files so that we don't have to repeat it in every file

#include <iostream>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
// #include <priority_queue>
#include <vector>
#include <list>
#include <math.h>
using namespace std;

void display_array(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}