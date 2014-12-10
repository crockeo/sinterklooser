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

// Loading the length.
int loadLength() {
    int length = 0;

    while (length == 0) {
        std::cout << "Enter the number of people:\n > ";
        std::cin >> length;
    }

    return length;
}

// Loading the names.
std::vector<std::string> loadNames(int length) {
    std::vector<std::string> names;
    std::string name;

    for (int i = 0; i < length; i++) {
        std::cout << "Enter name " << (i + 1) << ":\n > ";
        std::cin >> name;
        names.push_back(name);
    }

    return names;
}

// Loading the edges.
std::vector<Edge> loadEdges() {
    std::vector<Edge> edges;
    return edges;
}

// Loading the path.
std::string loadPath() {
    std::string path;
    std::cout << "Enter load path:\n > ";
    std::cin >> path;
    return path;
}

// The entry point to the application.
int main(int argc, char** argv) {
    std::cout << "Welcome to the digraph generator!\n"
              << "Follow the instructions below to get started!\n";

    // Getting all of the values.
    int len = loadLength();
    std::vector<std::string> names = loadNames(len);
    std::vector<Edge> edges = loadEdges();
    std::string path = loadPath();

    // Constructing the graph.
    Digraph* g = new Digraph(names);
    for (std::vector<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {
        g->connect(it->src, it->dst, it->weight);
    }

    // Writing it out.
    saveDigraph(path, g);

    // Cleaning up.
    delete g;
    return 0;
}
