#include"head.h"
int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    Node* nodes = new Node[V];
    for(int i = 0; i < V; i++) {
        cout << "Enter details for node " << i + 1 << ":\n";
        nodes[i].getDetails();
    }
    int** matrix = new int*[V];
    for(int i = 0; i < V; i++) {
        matrix[i] = new int[V];
        cout << "Enter adjacency for node " << nodes[i].id << " (0/1 for each vertex): ";
        for(int j = 0; j < V; j++) {
            cin >> matrix[i][j];

        }
    }
    Graph g(V, nodes, matrix);
    int choice, start;
    do {
        cout << "\n1. BFS\n2. DFS c\n3. Exit\nEnter choice: ";
        cin >> choice;
        if(choice == 1) {
            cout << "Enter start node id: ";
            cin >> start;
            g.BFS(start);
        }
        else if(choice == 2) {
            cout << "Enter start node id: ";
            cin >> start;
            g.DFS(start);
        }
    } while(choice != 3);
    for(int i = 0; i < V; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] nodes;
    return 0;

}
