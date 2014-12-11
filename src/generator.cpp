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
    int src, dst, weight;

    while (true) {
        std::cout << "Enter edge (enter '-1' for any of these to quit):\n";

        std::cout<< " | Enter source number:\n    > ";
        std::cin >> src;

        if (src == -1)
            break;

        std::cout << " | Enter destination number:\n    > ";
        std::cin >> dst;

        if (dst == -1)
            break;

        std::cout << " | Enter weight:\n    > ";
        std::cin >> weight;

        if (weight == -1)
            break;

        edges.push_back(Edge(src - 1, dst - 1, weight));
    }

    return edges;
}

// Loading the path.
std::string loadPath() {
    std::string path;
    std::cout << "Enter save path:\n > ";
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
