#include "graph.hpp"

//////////////
// Includes //
#include <string>
#include <vector>
#include <set>

//////////
// Code //

// Constructing an edge between two nodes.
Edge::Edge(int src, int dst, int weight) {
    this->src = src;
    this->dst = dst;
    this->weight = weight;
}

// An operator to compare edges (so they can be used in a set)
bool operator<(const Edge& e1, const Edge& e2) {
    if (e1.src < e2.src)
        return true;
    else if (e1.src == e2.src)
        return e1.dst < e2.dst;
    return false;
}

// Constructing a graph.
Graph::Graph(int size, std::vector<std::string> names) {
    this->size = size;
    this->names = names;
    this->edges = std::set<Edge>();
}

// Adding an edge.
int Graph::addEdge(const Edge& e) {
    this->edges.insert(e);
}

int Graph::addEdge(int src, int dst, int weight) {
    return this->addEdge(Edge(src, dst, weight));
}

// Removing an edge.
int Graph::removeEdge(const Edge& e) {
    return 0;
}

int Graph::removeEdge(int src, int dst) {
    return this->removeEdge(Edge(src, dst, 0));
}

// Determining the connection of two nodes.
int Graph::connected(int src, int dst) const {
    Edge e(src, dst, 0);
    return this->edges.find(e)->weight;
}

// Getting the size of the graph.
int Graph::getSize() const { return this->size; }

// Getting a name at an index.
std::string Graph::getName(int index) const { return this->names[index]; }
