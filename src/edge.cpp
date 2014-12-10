#include "edge.hpp"

// Comparing two edges.
bool operator<(const Edge& e1, const Edge& e2) {
    return e1.src < e2.src &&
           e1.dst < e2.dst;
}

// Constructing an edge between two points with a given weight.
Edge::Edge(int src, int dst, int weight) {
    this->src = src;
    this->dst = dst;
    this->weight = weight;
}
