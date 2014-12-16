#ifndef _NODE_HPP_
#define _NODE_HPP_

//////////////
// Includes //
#include <set>

//////////
// Code //

// A type to represent a node in a given graph.
struct Node {
    // Creating a node without any connections.
    Node(int);

    // Creating a node without any connections and with the default ID.
    Node();

    // Connecting this node with another node.
    void connect(Node*);

    // Disconnecting this node from another node.
    void disconnect(Node*);

    // Getting the weight of the node (number of nodes that are connected to it).
    int getWeight();

    // The unique ID of the Node.
    int id;

    // The set of nodes that this is connected to.
    std::set<Node*>* nodes;
};

#endif
