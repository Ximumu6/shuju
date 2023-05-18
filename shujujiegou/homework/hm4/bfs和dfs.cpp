#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include"F:/f/shujujiegou/graph/graph.cpp"
using namespace std;

unordered_set<int> bfs(Graph graph, int start) {
    unordered_set<int> visited;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        if (visited.find(vertex) == visited.end()) {
            visited.insert(vertex);
            for (auto neighbor : graph.get_vertices()[vertex]) {
                q.push(neighbor);
            }
        }
    }
    return visited;
}

unordered_set<int> dfs(Graph graph, int start, unordered_set<int> visited = {}) {
    visited.insert(start);
    for (auto neighbor : graph.get_vertices()[start]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited);
        }
    }
    return visited;
}
