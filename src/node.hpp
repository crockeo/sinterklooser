#ifndef _NODE_HPP_
#define _NODE_HPP_

//////////////
// Includes //
#include "array.hpp"

//////////
// Code //


struct Node {
    // Creating a node from a set of nodes.
    Node(Array<Node*>);

    // Creating a node without any connections.
    Node();

    // Connecting this node with another node.
    void connect(Node*);

    // The array of connections that exist from this node.
    Array<Node*> connections;
};

#endif
