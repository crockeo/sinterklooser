#ifndef _DIGRAPH_HPP_
#define _DIGRAPH_HPP_

//////////////
// Includes //
#include <set>

//////////
// Code //

// An edge between two nodes.
struct Edge {
    // Constructing an edge between two nodes.
    Edge(int, int);

    // Comparing one edge to another for the sake of a set.
    bool operator<(Edge);

    int src, dst;
};

// A class to represent a digraph.
class Digraph {
public:
    // Constructing an empty digraph.
    Digraph();

    // Destroying the graph.
    ~Digraph();

    // Connecting a given node to another node.
    void connect(int, int);

    // Removing the connection from the first node to another node.
    void disconnect(int, int);
    
    // Checking if the first node points at the second node.
    bool areConnected(int, int);

private:
    std::set<Edge>* edges;
};

#endif
