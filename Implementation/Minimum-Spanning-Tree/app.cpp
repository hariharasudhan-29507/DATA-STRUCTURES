#include"head.h"
int main()
{
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    Node *nodes = new Node[V];
    for (int i = 0; i < V; i++)
    {
        cout << "\nEnter details for node " << i + 1 << ":\n";
        nodes[i].getDetails();
    }

    int **matrix = new int *[V];
    for (int i = 0; i < V; i++)
    {
        matrix[i] = new int[V];
        cout << "\nEnter adjacency matrix row for vertex " << nodes[i].getName() << " (use 0 if no edge, weight if connected):\n";
        for (int j = 0; j < V; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Graph g(V, nodes, matrix);
    g.primMST();

    for (int i = 0; i < V; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] nodes;
return 0;
}
