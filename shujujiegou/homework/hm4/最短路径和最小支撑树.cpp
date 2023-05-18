#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <utility>
#include"F:/f/shujujiegou/graph/graph.cpp"
using namespace std;

typedef pair<int, int> pii;

unordered_map<int, int> dijkstra(Graph graph, int start) {
    unordered_map<int, int> distances;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (auto entry : graph.get_vertices()) {
        int vertex = entry.first;
        distances[vertex] = INT_MAX;
    }

    pq.push(make_pair(0, start));
    distances[start] = 0;

    while (!pq.empty()) {
        auto current = pq.top().second;
        pq.pop();

        for (auto neighbor : graph.get_vertices()[current]) {
            int newDist = distances[current] + 1; // assume the edge weight is 1
            if (newDist < distances[neighbor]) {
                pq.push(make_pair(newDist, neighbor));
                distances[neighbor] = newDist;
            }
        }
    }

    return distances;
}

set<pair<int, int>> kruskal_mst(Graph graph) {
    set<pair<int, int>> mst;

    // Define a vector of edges by iterating over the adjacency list and adding unique edges to the vector
    // We assume that the edge weight is 1 for simplicity
    vector<pair<int, pair<int, int>>> edges;
    for (auto entry : graph.get_vertices()) {
        int vertex = entry.first;
        for (auto neighbor : entry.second) {
            if (vertex <= neighbor) {
                edges.push_back(make_pair(1, make_pair(vertex, neighbor)));
            }
        }
    }



    // Iterate over the edges in increasing order of weight
    // Add each edge only if it doesn't create a cycle
    unordered_map<int, int> parent;
    for (int i = 0; i < edges.size(); i++) {
        auto edge = edges[i];
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        while (parent.find(u) != parent.end())
            u = parent[u];

        while (parent.find(v) != parent.end())
            v = parent[v];

        if (u != v) {
            mst.insert(edge.second);
            parent[u] = v;
        }
    }

    return mst;
}
int main() {
    Graph g;
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);
    g.add_vertex(5);

    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    g.add_edge(5, 2);

    auto res_dijkstra = dijkstra(g, 1);
    for (auto entry : res_dijkstra) {
        cout << entry.first << ": " << entry.second << endl;
    }
    // Output:
    // 1: 0
    // 2: 1
    // 3: 2
    // 4: 3
    // 5: 4
    
    auto res_kruskal = kruskal_mst(g);
    for (auto edge : res_kruskal) {
        cout << "(" << edge.first << ", " << edge.second << ")" << endl;
    }
    // Output:
    // (1, 2)
    // (2, 3)
    // (3, 4)
    // (4, 5)

    return 0;
}
