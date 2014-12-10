#include "digraph.hpp"

/////////////
// Imports //
#include <string>
#include <vector>
#include <set>

#include "edge.hpp"

//////////
// Code //

// Constructing a Digraph with a list of names.
Digraph::Digraph(std::vector<std::string> names) {
   this->names = new std::vector<std::string>;
   for (int i = 0; i < names.size(); i++)
       this->names->push_back(names[i]);

   this->edges = new std::set<Edge>;
}

// Constructing a Digraph without a list of names.
Digraph::Digraph() {
    this->names = new std::vector<std::string>;
    this->edges = new std::set<Edge>;
}

// Destroying a Digraph.
Digraph::~Digraph() {
    delete this->names;
    delete this->edges;
}

// Finding the weight of the connection between two nodes. If no connection
// exists, it should return 0.
int Digraph::connection(int src, int dst) {
    std::set<Edge>::iterator loc;
    loc = this->edges->find(Edge(src, dst, 0));

    if (loc == this->edges->end())
        return 0;

    return (*loc).weight;
}

// Connecting one node to another.
void Digraph::connect(int src, int dst, int weight) {
    this->edges->insert(Edge(src, dst, weight));
}

// Disconnecting one node from another.
void Digraph::disconnect(int src, int dst) {
    this->edges->erase(Edge(src, dst, 0));
}

// Connecting a node in both directions to another node.
void Digraph::connectBoth(int src, int dst, int weight) {
    this->connect(src, dst, weight);
    this->connect(dst, src, weight);
}

// Disconnecting a node in both directions from another node.
void Digraph::disconnectBoth(int src, int dst) {
    this->disconnect(src, dst);
    this->disconnect(dst, src);
}

// Getting a name for a given index. Returns a string of a number if a name
// doesn't exist.
std::string Digraph::getName(int index) {
    return this->names->at(index);
}

// Getting all of the names.
std::vector<std::string> Digraph::getNames() {
    return *this->names;
}

// Getting all of the edges.
std::set<Edge> Digraph::getEdges() {
    return *this->edges;
}
