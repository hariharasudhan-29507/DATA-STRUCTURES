#include"head.h"
maxheap::maxheap(int h) {
    capacity = pow(2, h + 1) - 1;
    arr = new Node[capacity];
    Size = 0;
}

maxheap::~maxheap() {
    delete[] arr;
}

void maxheap::insertion(Node element) {
    if (Size == capacity) {
        cout << "Heap full\n";
        return;
    }
    arr[Size] = element;
    percolateUp(Size);
    Size++;
}

Node maxheap::remove() {
    Node empty;
    if (Size == 0) {
        cout << "Heap empty\n";
        return empty;
    }
    Node ele = arr[0];
    arr[0] = arr[Size - 1];
    Size--;
    percolateDown(0);
    return ele;
}

void maxheap::percolateUp(int child) {
    if (child <= 0)
        return;
    int parent = (child - 1) / 2;
    if (arr[child].id > arr[parent].id) {
        Node t = arr[child];
        arr[child] = arr[parent];
        arr[parent] = t;
        percolateUp(parent);
    }
}

void maxheap::percolateDown(int root) {
    int large = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < Size && arr[left].id > arr[large].id)
        large = left;
    if (right < Size && arr[right].id > arr[large].id)
        large = right;
    if (large != root) {
        Node t = arr[root];
        arr[root] = arr[large];
        arr[large] = t;
        percolateDown(large);
    }
}

void maxheap::buildHeap(Node input[], int n) {
    if (n > capacity)
        n = capacity;

    for (int i = 0; i < n; i++)
        arr[i] = input[i];

    Size = n;

    for (int i = (Size / 2) - 1; i >= 0; i--)
        percolateDown(i);
}

int maxheap::search(int key) {
    for (int i = 0; i < Size; i++) {
        if (arr[i].id == key)
            return i;
    }
    return -1;
}

Node maxheap::findMax() {
    if (Size > 0)
        return arr[0];
    Node empty;
    return empty;
}

void maxheap::increaseBy(int key, int value) {
    int index = search(key);
    if (index == -1) {
        cout << "Key not found\n";
        return;
    }
    arr[index].id += value;
    percolateUp(index);
}

void maxheap::increaseTo(int key, int value) {
    int index = search(key);
    if (index == -1) {
        cout << "Key not found\n";
        return;
    }
    if (value < arr[index].id) {
        cout << "New value smaller, use decreaseTo\n";
        return;
    }
    arr[index].id = value;
    percolateUp(index);
}

void maxheap::decreaseBy(int key, int value) {
    int index = search(key);
    if (index == -1) {
        cout << "Key not found\n";
        return;
    }
    arr[index].id -= value;
    percolateDown(index);
}

void maxheap::decreaseTo(int key, int value) {
    int index = search(key);
    if (index == -1) {
        cout << "Key not found\n";
        return;
    }
    if (value > arr[index].id) {
        cout << "New value larger, use increaseTo\n";
        return;
    }
    arr[index].id = value;
    percolateDown(index);
}

void maxheap::heapSort() {
    int originalSize = Size;
    for (int i = Size - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        Size--;
        percolateDown(0);
    }
    cout << "Sorted elements (ID Name): \n";
    cout<<"ID\t NAME"<<endl;
    for (int i = 0; i < originalSize; i++)
        cout << arr[i].id<<"\t" << arr[i].name<<endl;
    Size = originalSize;
}

void maxheap::display() {
    cout<<"ID"<<" "<<"Name"<<" "<<endl;

    for (int i = 0; i < Size; i++)
        cout << arr[i].id<<" "<<arr[i].name<<"\n";
    cout << endl;
}
