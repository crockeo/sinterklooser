#ifndef _EDGE_HPP_
#define _EDGE_HPP_

//////////
// Code //

// Comparing two edges.
bool operator<(const Edge&, const Edge&);

// A class to represent an edge between two points.
struct Edge {
    // Constructing an edge between two points with a given weight.
    Edge(int, int, int);
    
    int src, dst;
    int weight;
};

#endif
