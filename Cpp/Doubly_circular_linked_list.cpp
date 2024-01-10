#include "header.h"

struct node{
    int data;
    struct node *next;
    struct node *pre;
};

class doubly_circular_linked_list{
    int size;
    struct node* head, *tail;

  public :

    doubly_circular_linked_list() {
        size = 0;
        head = tail = nullptr;
    }

    void insert_at_start (int num) { insert_at_position(num, 1);      }
    void insert_at_end (int num)   { insert_at_position(num, size+1); }
    void delete_from_start ()      { delete_from_position(1);         }
    void delete_from_end ()        { delete_from_position(size);      }

    void insert_at_position(int num, int pos){
        // check that this position is possible or not
        if(pos > 0 && pos <= size+1){
            struct node *new_element = new struct node;
            new_element->data = num;
            new_element->next = new_element->pre = nullptr;

            // checks if this is not the first time
            if(head){

                if (pos == 1) { // starting position
                    new_element->next = head;
                    head->pre = new_element;
                    head = new_element;
                    tail->next = head;
                    head->pre = tail;
                } else if (pos == size + 1) { // last position
                    new_element->pre = tail;
                    tail->next = new_element;
                    tail = new_element;
                    tail->next = head;
                    head->pre = tail;

                } else {
                    struct node *temp = head;
                    int count = 1;
                    // go to that position
                    while(count < pos) {
                        temp = temp->next;
                        count++;
                    }
                    // put element in between
                    new_element->next = temp;
                    new_element->pre = temp->pre;
                    temp->pre->next = new_element;
                    temp->pre = new_element;
                }
            } else { // if list is empty
                head = tail = new_element;
            }
            size++;
        } else {
            cout << "Cannot add element at this position" << endl;
        }
    }

    void delete_from_position(int pos){
        if(pos > 0 && pos <= size) {
            // variable to hold values temporarily
            struct node* temp = nullptr;

            // checks if there are more elements other than head
            if(size > 1) {
                if(pos == 1) { // first position
                    temp = head;
                    head = head->next;
                    head->pre = tail;
                    tail->next = head;
                } else if(pos == size) { // last position
                    temp = tail;
                    tail = tail->pre;
                    tail->next = head;
                    head->pre = tail;
                } else {
                    temp = head;
                    int count = 1;
                    // go to that position
                    while (count < pos){
                        temp = temp->next;
                        count++;
                    }
                    // connect the neighbours to each other
                    temp->pre->next = temp->next;
                    temp->next->pre = temp->pre;
                }
            } else { // when there is only head
                temp = head;
                head = tail = nullptr;
            }
            // free the node
            delete temp;
            size--;
        } else {
            string msg = head ? "There is no element at this position" : "List is empty";
            cout << msg << endl;
        }
    }

    void display(){
        if(head) {
            struct node* temp = head;
            int count = 1;
            while(count <= size){
                cout << temp->data << ", ";
                temp = temp->next;
                count++;
            }
            cout << endl;
        } else {
            cout << "Linked List is empty" << endl;
        }
    }
};

int main(){
    int n = 0, number = -1, position = -1;
    doubly_circular_linked_list dl;

    do{
        cout << "Enter number for following operations : " << endl;
        cout << "1. Insert at start \t\t\t5. Delete from start \n2. Insert at End \t\t\t6. Delete from end \n3. Insert at specific position \t\t7. Delete at specific position \n4. Display Linked List \t\t\t8. Exit\n";
        cin >> n;
        switch(n){
            case 1: 
                cout << "Number to be pushed : ";
                cin >> number;
                dl.insert_at_start(number);
                break;
            
            case 2: 
                cout << "Number to be pushed : ";
                cin >> number;
                dl.insert_at_end(number);
                break;
            
            case 3:
                cout << "Number and position to be pushed : ";
                cin >> number >> position;
                dl.insert_at_position(number, position);
                break;

            case 4:
                dl.display();
                break;

            
            case 5: 
                dl.delete_from_start();
                break;
            
            case 6: 
                dl.delete_from_end();
                break;
            
            case 7:
                cout << "Position of element to delete : ";
                cin >> position;
                dl.delete_from_position(position);
                break;

            case 8: 
                cout << "Exiting" << endl;
                break;
            
            default :
                cout << "Enter a valid number" << endl;
        }
        number = -1, position = -1;
    } while(n!=8);

    return 0;
}