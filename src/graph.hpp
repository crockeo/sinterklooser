#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

//////////////
// Includes //
#include "node.hpp"

//////////
// Code //

// A class to represent a digital graph.
class Graph {
public:
    // Creating a graph with size n and no connections.
    Graph(int);

    // Deleting the graph.
    ~Graph();

    // Connecting two nodes on the graph.
    void connect(int, int);

    // Disconnecting two nodes on the graph.
    void disconnect(int, int);

    // Checking if two nodes on the graph are connected.
    bool areConnected(int, int);

    // Getting the length of the graph.
    int getLength();
private:
    int length;
    Node* nodes;
};

#endif
