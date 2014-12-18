#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

//////////////
// Includes //
#include <string>
#include <vector>
#include <set>

//////////
// Code //

// A type to represent an edge.
struct Edge {
    int src, dst, weight;

    // Constructing an edge between two nodes.
    Edge(int, int, int);
};

// An operator to compare edges (so they can be used in a set)
bool operator<(const Edge&, const Edge&);

// A class to represent a graph.
class Graph {
private:
    int size;
    std::vector<std::string> names;
    std::set<Edge> edges;

public:
    // Constructing a graph.
    Graph(int, std::vector<std::string>);

    // Adding an edge.
    int addEdge(const Edge&);
    int addEdge(int, int, int);

    // Removing an edge.
    int removeEdge(const Edge&);
    int removeEdge(int, int);

    // Determining the connection of two nodes.
    int connected(int, int) const;

    // Getting the size of the graph.
    int getSize() const;

    // Getting a name at an index.
    std::string getName(int) const;
};

#endif
