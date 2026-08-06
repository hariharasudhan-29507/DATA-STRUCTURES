#include"head.h"
MinHeap::MinHeap(int height) {
    capacity = pow(2, height + 1) - 1;
    arr = new int[capacity];
    size = 0;
}

MinHeap::~MinHeap() {
    delete[] arr;
}

bool MinHeap::isEmpty() {
    return size == 0;
}

bool MinHeap::isFull() {
    return size == capacity;
}

int MinHeap::insertion(int val) {
    if (isFull()) return 0;

    arr[size] = val;
    if (size > 0) {
        percolateUp(size);
    }
    size++;
    return 1;
}

void MinHeap::percolateUp(int idx) {
    if (idx > 0) {
        int parent = (idx - 1) / 2;
        if (arr[idx] < arr[parent]) {
            swap(arr[idx], arr[parent]);
            percolateUp(parent);
        }
    }
}

void MinHeap::percolateDown(int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int smallest = idx;

    if (left < size && arr[left] < arr[smallest]) smallest = left;
    if (right < size && arr[right] < arr[smallest]) smallest = right;

    if (smallest != idx) {
        swap(arr[idx], arr[smallest]);
        percolateDown(smallest);
    }
}

int MinHeap::deleteMin() {
    if (isEmpty()) return -1;

    int minVal = arr[0];
    arr[0] = arr[size - 1];
    size--;
    percolateDown(0);
    return minVal;
}

void MinHeap::increaseBy(int elt, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == elt) {
            arr[i] += val;
            percolateDown(i);
            return;
        }
    }
}

void MinHeap::increaseTo(int elt, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == elt) {
            arr[i] = val;
            percolateDown(i);
            return;
        }
    }
}

void MinHeap::decreaseBy(int elt, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == elt) {
            arr[i] -= val;
            percolateUp(i);
            return;
        }
    }
}

void MinHeap::decreaseTo(int elt, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == elt) {
            arr[i] = val;
            percolateUp(i);
            return;
        }
    }
}

void MinHeap::buildHeap(int input[], int n) {
    if (n > capacity) n = capacity;

    for (int i = 0; i < n; i++) arr[i] = input[i];
    size = n;

    for (int i = (size / 2) - 1; i >= 0; i--) {
        percolateDown(i);
    }
}

void MinHeap::heapSort() {
    int *backup = new int[size];
    for (int i = 0; i < size; i++) backup[i] = arr[i];

    int oldSize = size;
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        size--;
        percolateDown(0);
    }

    cout << "Heap Sort result: ";
    for (int i = 0; i < oldSize; i++) cout << arr[i] << " ";
    cout << endl;

    // restore original heap
    for (int i = 0; i < oldSize; i++) arr[i] = backup[i];
    size = oldSize;
    delete[] backup;
}

void MinHeap::display() {
    cout << "Heap elements: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}
