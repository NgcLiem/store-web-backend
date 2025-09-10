#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int destination;
    int weight;
};

// Structure to represent a vertex
struct Vertex {
    int id;
    int distance;
    vector<Edge> edges;
};

// Dijkstra's algorithm implementation
void dijkstra(vector<Vertex>& graph, int start) {
    // Priority queue to store vertices based on distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Set initial distances to infinity for all vertices
    for (auto& vertex : graph) {
        vertex.distance = numeric_limits<int>::max();
    }
    
    // Set distance to source vertex as 0
    graph[start].distance = 0;
    pq.push({0, start});
    
    // Dijkstra's algorithm loop
    while (!pq.empty()) {
        // Extract the vertex with minimum distance
        int u = pq.top().second;
        pq.pop();
        
        // Iterate through all adjacent vertices of u
        for (const Edge& edge : graph[u].edges) {
            int v = edge.destination;
            int weight = edge.weight;
            
            // Relaxation step
            if (graph[u].distance != numeric_limits<int>::max() && 
                graph[u].distance + weight < graph[v].distance) {
                graph[v].distance = graph[u].distance + weight;
                pq.push({graph[v].distance, v});
            }
        }
    }
}

int main() {
    // Example usage
    int numVertices = 5;
    vector<Vertex> graph(numVertices);

    // Add edges
    graph[0].edges.push_back({1, 10});
    graph[0].edges.push_back({2, 5});
    graph[1].edges.push_back({2, 2});
    graph[1].edges.push_back({3, 1});
    graph[2].edges.push_back({1, 3});
    graph[2].edges.push_back({3, 9});
    graph[2].edges.push_back({4, 2});
    graph[3].edges.push_back({4, 4});

    // Run Dijkstra's algorithm from vertex 0
    dijkstra(graph, 0);

    // Output the shortest distances
    for (int i = 0; i < numVertices; ++i) {
        cout << "Shortest distance from vertex 0 to vertex " << i << " is: " << graph[i].distance << endl;
    }

    return 0;
}
