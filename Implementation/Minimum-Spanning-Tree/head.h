#include <iostream>
#include <string>
using namespace std;

class Node
{
    int id;
    string name;

public:
    Node();
    void getDetails();
    int getId();
    string getName();
};

class Graph
{
    int V;
    Node *nodes;
    int **graph;

public:
    Graph(int vertices, Node *n, int **matrix);
    ~Graph();
    int minKey(int key[], bool mstSet[]);

    void primMST();
};

