#include "node.hpp"

//////////////
// Includes //
#include "array.hpp"

//////////
// Code //

// Creating a node from a set of nodes.
Node::Node(Array<Node*> connections) {
    this->connections = new Array<Node*>(connections.getSize());
    for (int i = 0; i < connections.getLength(); i++)
        this->connections->pushRight(connections[i]);
}

// Creating a node without any connections.
Node::Node() {
    this->connections = new Array<Node*>;
}

// Connecting this node with another node.
void Node::connect(Node* node) {
    this->connections->pushRight(node);
}
