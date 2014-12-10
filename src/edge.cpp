#include "edge.hpp"

// Constructing an edge between two points with a given weight.
Edge::Edge(int src, int dst, int weight) {
    this->src = src;
    this->dst = dst;
    this->weight = weight;
}
