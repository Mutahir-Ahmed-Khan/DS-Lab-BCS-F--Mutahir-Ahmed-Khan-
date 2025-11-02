#include <iostream>
using namespace std;

class MyQueue {
public: 
    int size;
    int cap;
    int *arr;

    MyQueue(int capp) {
        size = 0;
        cap = capp;
        arr = new int[capp];
    }

    // Destructor to free memory
    ~MyQueue() {
        delete[] arr;
    }

    bool isFull() {
        return size == cap;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "The Queue is Full" << endl;
        } else {
            arr[size] = val;
            size++;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "The Queue is Empty" << endl;
            return -1;  // Indicate error
        } else {
            int temp = arr[0];
            for (int i = 1; i < size; i++) {
                arr[i - 1] = arr[i];
            }
            size--;
            return temp;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    return 0;
}
