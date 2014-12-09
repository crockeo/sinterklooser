#include "digraph.hpp"

//////////////
// Includes //
#include <functional>
#include <set>

//////////
// Code //

// Checking the ordering of two edges.
bool operator<(const Edge& e1, const Edge& e2) {
    return e1.src < e2.src &&
           e1.dst < e2.dst;
}

// Constructing an edge between two nodes.
Edge::Edge(int src, int dst) {
    this->src = src;
    this->dst = dst;
}

// Constructing an empty digraph.
Digraph::Digraph() {
    this->edges = new std::set<Edge>;
}

// Destroying the graph.
Digraph::~Digraph() {
    delete this->edges;
}

// Connecting a given node to another node.
void Digraph::connect(int src, int dst) {
    this->edges->insert(Edge(src, dst));
}

// Removing the connection from the first node to another node.
void Digraph::disconnect(int src, int dst) {
    this->edges->erase(Edge(src, dst));
}

// Checking if the first node points at the second node.
bool Digraph::areConnected(int src, int dst) {
    return this->edges->count(Edge(src, dst)) > 0;
}
