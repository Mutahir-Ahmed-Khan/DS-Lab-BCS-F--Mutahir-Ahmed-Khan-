#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* leftChild;
    node* rightChild;

    node(int value) {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class MinHeap {
public:
    node* heap[100];
    int size;

    MinHeap() {
        size = 0;
    }

    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftIndex(int index) {
        return 2 * index + 1;
    }

    int rightIndex(int index) {
        return 2 * index + 2;
    }

    void heapifyUp(int index) {
        while (index != 0 && heap[index]->data < heap[parent(index)]->data) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int left = leftIndex(index);
        int right = rightIndex(index);
        int smallest = index;

        if (left < size && heap[left]->data < heap[smallest]->data) {
            smallest = left;
        }
        
        if (right < size && heap[right]->data < heap[smallest]->data) {
            smallest = right;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void insert(int value) {
        if (size == 100) {
            cout << "Heap is overflowed" << endl;
            return;
        }

        heap[size] = new node(value);
        heapifyUp(size);
        size++;
    }

    void deleteMin() {
        if (size == 0) {
            cout << "Heap underflow!\n";
            return;
        }

        cout << "Deleted element: " << heap[0]->data << endl;
        heap[0] = heap[size - 1];
        size--;

        heapifyDown(0);
    }
};

int main() {
    MinHeap myHeap;

    myHeap.insert(10);
    myHeap.insert(5);
    myHeap.insert(20);
    myHeap.insert(1);

    myHeap.deleteMin();

    return 0;
}
