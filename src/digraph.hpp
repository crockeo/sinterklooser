#ifndef _DIGRAPH_HPP_
#define _DIGRAPH_HPP_

/////////////
// Imports //
#include <string>
#include <vector>
#include <set>

#include "edge.hpp"

//////////
// Code //

// A class to represent a directed graph.
class Digraph {
public:
    // Constructing a Digraph with a list of names.
    Digraph(std::vector<std::string>);

    // Constructing a Digraph without a list of names.
    Digraph();

    // Destroying a Digraph.
    ~Digraph();

    // Finding the weight of the connection between two nodes. If no connection
    // exists, it should return 0.
    int connection(int, int);

    // Connecting one node to another.
    void connect(int, int, int);

    // Disconnecting one node from another.
    void disconnect(int, int);

    // Connecting a node in both directions to another node.
    void connectBoth(int, int, int);

    // Disconnecting a node in both directions from another node.
    void disconnectBoth(int, int);

    // Getting a name for a given index. Returns a string of a number if a name
    // doesn't exist.
    std::string getName(int);

    // Getting all of the names.
    std::vector<std::string> getNames();

    // Getting all of the edges.
    std::set<Edge> getEdges();

private:
    std::vector<std::string>* names;
    std::set<Edge>* edges;
};

#endif
