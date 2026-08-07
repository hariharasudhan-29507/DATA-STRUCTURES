#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    int id;
    string name;
    Node();
    void getDetails();
    void displayDetails();
};
class Queue {
    Node* queuearr;
    int capacity;
    int front;
    int rear;
public:
    Queue(int );
    ~Queue();
    int enqueue(Node);
    Node dequeue();
    int isFull();
    int isEmpty();
};
class Graph {
    int V;
    Node* nodes;
    int** adj;

public:
    Graph(int vertices, Node* n, int** matrix);
    ~Graph();
    void BFS(int startID);
    void DFS(int startID);
    void DFSRecursive(int node, bool visited[]);

};
