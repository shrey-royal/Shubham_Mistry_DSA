#include <iostream>
#include <climits>
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

void breadth_first_search(Graph* graph, int start) {
    bool* visited = new bool[graph->vertices];
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }

    int queue[100];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        cout << v << " ";

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adj[v][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    delete[] visited;
}

void addWeightedEdge(Graph* graph, int u, int v, int weight) {
    graph->adj[u][v] = weight;
    graph->adj[v][u] = weight;  // For Undirected Graph
}

int minDistance(int dist[], bool visited[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

void dijkstra(Graph* graph, int start) {
    int vertices = graph->vertices;
    int* dist = new int[vertices];
    bool* visited = new bool[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[start] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);

        visited[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph->adj[u][v] && dist[u] != INT_MAX && dist[u] + graph->adj[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->adj[u][v];
            }
        }
    }

    cout << "Vertex \t Distance from Source " << start << "\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << " \t\t" << dist[i] << "\n";
    }

    delete[] dist;
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
    int vertices = 16;  // Total number of vertices (0 to 15)
    Graph* graph = createGraph(vertices);

    // Adding edges to the graph
    // addEdge(graph, 0, 1);
    // addEdge(graph, 0, 2);
    // addEdge(graph, 1, 2);
    // addEdge(graph, 1, 3);
    // addEdge(graph, 2, 3);
    // addEdge(graph, 3, 4);

    // addEdge(graph, 0, 1);
    // addEdge(graph, 0, 2);
    // addEdge(graph, 0, 5);
    // addEdge(graph, 1, 2);
    // addEdge(graph, 1, 3);
    // addEdge(graph, 1, 6);
    // addEdge(graph, 2, 3);
    // addEdge(graph, 2, 7);
    // addEdge(graph, 3, 4);
    // addEdge(graph, 3, 8);
    // addEdge(graph, 4, 9);
    // addEdge(graph, 5, 6);
    // addEdge(graph, 5, 10);
    // addEdge(graph, 6, 7);
    // addEdge(graph, 6, 11);
    // addEdge(graph, 7, 8);
    // addEdge(graph, 7, 12);
    // addEdge(graph, 8, 9);
    // addEdge(graph, 8, 13);
    // addEdge(graph, 9, 14);
    // addEdge(graph, 10, 11);
    // addEdge(graph, 10, 15);
    // addEdge(graph, 11, 12);
    // addEdge(graph, 12, 13);
    // addEdge(graph, 13, 14);
    // addEdge(graph, 14, 15);


    // cout << "\nDFS traversal starting from vertex 0:\n";
    // depth_first_search(graph, 0);

    // cout << "\nBFS traversal starting from vertex 0:\n";
    // breadth_first_search(graph, 0);

    addWeightedEdge(graph, 0, 1, 4);
    addWeightedEdge(graph, 0, 2, 3);
    addWeightedEdge(graph, 0, 5, 7);
    addWeightedEdge(graph, 1, 2, 1);
    addWeightedEdge(graph, 1, 3, 2);
    addWeightedEdge(graph, 1, 6, 5);
    addWeightedEdge(graph, 2, 3, 8);
    addWeightedEdge(graph, 2, 7, 10);
    addWeightedEdge(graph, 3, 4, 2);
    addWeightedEdge(graph, 3, 8, 6);
    addWeightedEdge(graph, 4, 9, 1);
    addWeightedEdge(graph, 5, 6, 2);
    addWeightedEdge(graph, 5, 10, 5);
    addWeightedEdge(graph, 6, 7, 3);
    addWeightedEdge(graph, 6, 11, 4);
    addWeightedEdge(graph, 7, 8, 1);
    addWeightedEdge(graph, 7, 12, 2);
    addWeightedEdge(graph, 8, 9, 4);
    addWeightedEdge(graph, 8, 13, 8);
    addWeightedEdge(graph, 9, 14, 2);
    addWeightedEdge(graph, 10, 11, 3);
    addWeightedEdge(graph, 10, 15, 6);
    addWeightedEdge(graph, 11, 12, 1);
    addWeightedEdge(graph, 12, 13, 2);
    addWeightedEdge(graph, 13, 14, 7);
    addWeightedEdge(graph, 14, 15, 3);

    cout << "Dijkstra's algorithm starting from vertex 0:\n";
    dijkstra(graph, 0);

    cout << endl;

    freeGraph(graph);

    return 0;
}