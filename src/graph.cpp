#include "graph.hpp"

//////////////
// Includes //
#include <string>

#include "node.hpp"

//////////
// Code //

// Creating a graph with size n, no connections, and with every name mapped
// to their respective node.
Graph::Graph(std::string* names, int length) {
    this->length = length;

    this->names = new std::string[this->getLength()];
    this->nodes = new Node[this->getLength()];

    for (int i = 0; i < this->getLength(); i++) {
        this->names[i] = names[i];
        this->nodes[i] = Node(i);
    }
}

// Creating a graph with size n and no connections.
Graph::Graph(int length) {
    this->length = length;

    this->names = new std::string[this->getLength()];
    this->nodes = new Node[this->getLength()];

    for (int i = 0; i < this->getLength(); i++) {
        this->names[i] = "No name.";
        this->nodes[i] = Node(i);
    }
}

// Deleting the graph.
Graph::~Graph() {
    delete[] this->nodes;
}

// Connecting two nodes on the graph.
void Graph::connect(int n1, int n2) {
    this->nodes[n1].connect(&this->nodes[n2]);
    this->nodes[n2].connect(&this->nodes[n1]);
}

// Disconnecting two nodes on the graph.
void Graph::disconnect(int n1, int n2) {
    this->nodes[n1].disconnect(&this->nodes[n2]);
    this->nodes[n2].disconnect(&this->nodes[n1]);
}

// Checking if two nodes on the graph are connected.
bool Graph::areConnected(int n1, int n2) {
    return this->nodes[n1].nodes->count(&this->nodes[n2]) > 0;
}

// Getting the length of the graph.
int Graph::getLength() { return this->length; };

// Getting the name of a node.
std::string Graph::getName(int index) { return this->names[index]; }

// Getting all of the names.
std::string* Graph::getNames() { return this->names; }

// Getting a specific node.
Node Graph::getNode(int index) { return this->nodes[index]; }
