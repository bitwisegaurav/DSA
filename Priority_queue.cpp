#include "header.h"

void shift_numbers(int **arr, int start, int end){
    for(int i = end; i > start; i--){
        arr[0][i] = arr[0][i-1];
        arr[1][i] = arr[1][i-1];
    }
}

class priorityQueue{
    int size, top;
    int **arr;

  public :
    
    priorityQueue(){
        size = 10;
        top = -1;
        arr = new int*[2];
        for (int i = 0; i < 2; ++i) {
            arr[i] = new int[size];
        }
    }

    void push(int num, int priority){
        if(top < size){
            top++;
            int index = 0;
            while(index < top && arr[1][index] <= priority) index++;
            shift_numbers(arr, index, top);
            arr[0][index] = num;
            arr[1][index] = priority;
        } else {
            cout << "Priority Queue is full!" << endl;
        }
    }

    void pop(){
        if(top > 0) {
            top--;
        } else {
            cout << "Priority Queue is empty!" << endl;
        }
    }

    int peek(){
        if(top > 0){
            return arr[0][top];
        } else {
            cout << "Priority Queue is empty!" << endl;
            return NULL;
        }
    }

    void display(){
        for (int i=0; i<=top; i++) {
            printf("(%d, %d), ",arr[0][i],arr[1][i]);
        }
        cout << endl;
    }
};

int main(){
    int n = 0, number = -1, priority = -1;
    priorityQueue pq;
    do{
        cout << "Enter number for following operations : " << endl;
        cout << "1. Push \t2. Pop \t3. Peek \t4. Display Priority Queue (element, priority) \t5. Exit\n";
        cin >> n;
        switch(n){
            case 1: 
                cout << "Number and priority to be pushed : ";
                cin >> number >> priority;
                pq.push(number, priority);
                break;
            
            case 2:
                pq.pop();
                break;
            
            case 3:
                int val = pq.peek();
                if(val) cout << "Peek element = " << val << endl;
                break;

            case 4:
                pq.display();
                break;

            case 5: 
                cout << "Exiting" << endl;
                break;
            
            default :
                cout << "Enter a valid number" << endl;
        }
    } while(n!=5);

    return 0;
}