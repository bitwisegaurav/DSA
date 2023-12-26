#include "header.h"

class qu{
    int size, end;
    int* arr;

  public:
    qu(){
        size = 10;
        end = -1;
        arr = new int[size];
    }
    void push(int num){
        if(end<size){
            arr[++end] = num;
        } else {
            cout << "Queue is Full!" << endl;
        }
    }

    void pop(){
        if(end>=0){
            for (int i = 0; i < end; i++)
                arr[i] = arr[i+1];
            end--;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    int end_element(){
        if(end>=0){
            return arr[end];
        } else {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }

    void display(){
        cout << "Queue : ";
        for(int i=0; i<=end; i++){
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
};

int main(){
    int n = 0, number = -1;
    qu q;
    do{
        cout << "Enter number for following operations : " << endl;
        cout << "1. Push \n2. Pop \n3. end \n4. Display Queue \n5. Exit\n";
        cin >> n;
        switch(n){
            case 1: 
                cout << "Number to be pushed : ";
                cin >> number;
                q.push(number);
                break;
            
            case 2:
                q.pop();
                break;
            
            case 3:
                cout << "end element = " << q.end_element() << endl;
                break;

            case 4:
                q.display();
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