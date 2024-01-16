#include "header.h"

class heap {
    int arr[100];
    int size;

  public:

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index/2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
            }
            else break;
        }
    }

    void remove() {
        if(size == 0) {
            cout << "Heap is empty!!" << endl;
            return;
        }

        arr[1] = arr[size];
        int index = 1;

        while (index < size)
        {
            int left = 2*index;
            int right = 2*index + 1;

            if(left < size && arr[left] > arr[index]) {
                swap(arr[left], arr[index]);
                index = left;
            } else if(right < size && arr[right] > arr[index]) {
                swap(arr[right], arr[index]);
                index = right;
            } else break;
        }
        
        size--;
    }

    void display() {
        cout << "Heap: ";
        for(int i=1; i<=size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h;
    h.insert(55);
    h.insert(50);
    h.insert(53);
    h.insert(54);
    h.insert(52);
    h.display();
    cout << endl;
    h.remove();
    h.display();

    return 0;
}