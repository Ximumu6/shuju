#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class Graph {
private:
    unordered_map<int, list<int>> vertices;
public:
    void add_vertex(int);
    void add_edge(int, int);
    unordered_map<int, list<int>> get_vertices();
};

void Graph::add_vertex(int v) {
    vertices[v] = list<int>();
}

void Graph::add_edge(int v1, int v2) {
    vertices[v1].push_back(v2);
    vertices[v2].push_back(v1);
}

unordered_map<int, list<int>> Graph::get_vertices() {
    return vertices;
}
