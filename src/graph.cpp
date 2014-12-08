#include "graph.hpp"

//////////////
// Includes //
#include "node.hpp"

//////////
// Code //

// Creating a graph with size n and no connections.
Graph::Graph(int length) {
    this->length = length;

    this->nodes = new Node[this->getLength()];
    for (int i = 0; i < this->getLength(); i++)
        this->nodes[i] = Node(i);
}

// Deleting the graph.
Graph::~Graph() {
    delete[] this->nodes;
}

// Connecting two nodes on the graph.
void Graph::connect(int n1, int n2) {
    this->nodes[n1].connect(&this->nodes[n2]);
}

// Disconnecting two nodes on the graph.
void Graph::disconnect(int n1, int n2) {
    this->nodes[n1].disconnect(&this->nodes[n2]);
}

// Checking if two nodes on the graph are connected.
bool Graph::areConnected(int n1, int n2) {
    return this->nodes[n1].nodes->count(&this->nodes[n2]) > 0;
}

// Getting the length of the graph.
int Graph::getLength() { return this->length; };
