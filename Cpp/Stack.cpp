#include "header.h"

class st{
    int size, top;
    int* arr;

  public:
    st(){
        size = 10;
        top = 0;
        arr = new int[size];
    }
    void push(int num){
        if(top<size){
            arr[top++] = num;
        } else {
            cout << "Stack is Full!" << endl;
        }
    }

    void pop(){
        if(top>0){
            top--;
        } else {
            cout << "Stack is empty!" << endl;
        }
    }

    int top_element(){
        if(top>0){
            return arr[top-1];
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }

    void display(){
        cout << "Stack : ";
        for(int i=0; i<top; i++){
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
};

int main(){
    int n = 0, number = -1;
    st s;
    do{
        cout << "Enter number for following operations : " << endl;
        cout << "1. Push \n2. Pop \n3. Top \n4. Display Stack \n5. Exit\n";
        cin >> n;
        switch(n){
            case 1: 
                cout << "Number to be pushed : ";
                cin >> number;
                s.push(number);
                break;
            
            case 2:
                s.pop();
                break;
            
            case 3:
                cout << "Top element = " << s.top_element() << endl;
                break;

            case 4:
                s.display();
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