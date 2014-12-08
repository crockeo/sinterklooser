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
    // Creating a graph with size n, no connections, and with every name mapped
    // to their respective node.
    Graph(std::string*, int);

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

    // Getting the name of a node.
    std::string getName(int);

    // Getting a specific node.
    Node getNode(int);
private:
    int length;
    std::string* names;
    Node* nodes;
};

#endif
