#include <iostream>
using namespace std;

struct Graph {
    int** adj;
    int vertices;
};

Graph* createGraph(int vertices) {
    Graph* graph = new Graph;
    graph->vertices = vertices;

    graph->adj = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        graph->adj[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

void explore(Graph* graph, int v, bool* visited) {
    cout << v << " ";
    visited[v] = true;

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[v][i] && !visited[i]) {
            explore(graph, i, visited);
        }
    }
}

void depth_first_search(Graph* graph, int start) {
    bool* visited = new bool[graph->vertices];
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }
    explore(graph, start, visited);
    delete[] visited;
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        delete[] graph->adj[i];
    }
    delete[] graph->adj;
    delete graph;
}

int main() {
    int vertices = 5;  // Total number of vertices (0 to 4)
    Graph* graph = createGraph(vertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);


    cout << "DFS traversal starting from vertex 0:\n";
    depth_first_search(graph, 1);

    cout << endl;

    freeGraph(graph);

    return 0;
}