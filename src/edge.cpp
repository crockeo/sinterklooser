#include "edge.hpp"

// Constructing an edge between two points with a given weight.
Edge::Edge(int src, int dst, int weight) {
    this->src = src;
    this->dst = dst;
    this->weight = weight;
}

// Comparing two edges.
bool operator<(const Edge& e1, const Edge& e2) {
    if (e1.src < e2.src)
        return true;
    else if (e1.src == e2.src)
        return e1.dst < e2.dst;
    else
        return false;
}
