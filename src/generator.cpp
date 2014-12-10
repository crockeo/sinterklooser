//////////////
// Includes //
#include <iostream>
#include <string>
#include <vector>

#include "digraph.hpp"
#include "edge.hpp"
#include "io.hpp"

//////////
// Code //

// TODO: Implement each part.

// Loading the length.
int loadLength() {

}

// Loading the names.
std::vector<std::string> loadNames() {

}

// Loading the edges.
std::vector<Edge> loadEdges() {

}

// Loading the path.
std::string loadPath() {

}

// The entry point to the application.
int main(int argc, char** argv) {
    std::cout << "Welcome to the digraph generator!\n"
              << "Follow the instructions below to get started!\n";

    int len = loadLength();
    std::vector<std::string> names = loadNames();
    std::vector<Edge> edges = loadEdges();
    std::string path = loadPath();

    Digraph* g = new Digraph(names);
    for (std::vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {
        g->connect(it->src, it->dst, it->weight);
    }

    saveDigraph(path, g);
    delete g;
    return 0;
}
