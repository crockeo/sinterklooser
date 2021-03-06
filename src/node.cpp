#include "node.hpp"

//////////////
// Includes //
#include <limits.h>
#include <set>

//////////
// Code //

// Creating a node without any connections.
Node::Node(int id) {
    this->id = id;
    this->nodes = new std::set<Node*>;
}

// Creating a node without any connections and with the default ID.
Node::Node() {
    this->id = 0;
    this->nodes = new std::set<Node*>;
}

// Connecting this node with another node.
void Node::connect(Node* node) {
    this->nodes->insert(node);
}

// Disconnecting this node from another node.
void Node::disconnect(Node* node) {
    this->nodes->erase(node);
}

// Getting the weight of the node (number of nodes that are connected to it).
int Node::getWeight() {
    int n = 0;
    for (auto it = this->nodes->begin(); it != this->nodes->end(); it++)
        n++;

    if (n == 0)
        return INT_MAX;
    return n;
}
