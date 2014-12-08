#include "io.hpp"

//////////////
// Includes //
#include <iostream>
#include <fstream>

#include "graph.hpp"

//////////
// Code //

// Loading a graph from a file.
Graph* loadGraph(std::string path) {
    // TODO: load the graph.
    return 0;
}

// Saving a graph to the file system.
int saveGraph(std::string path, Graph* g) {
    // TODO: Save the graph.
    return 0;
}

// Writing a graph to std out.
int coutGraph(Graph* g) {
    for (int i = 0; i < g->getLength(); i++) {
        std::cout << "Cerek knows:\n";
        for (int j = 0; j < g->getLength(); j++) {
            if (i == j)
                continue;
            if (g->areConnected(i, j))
                std::cout << " - " << g->getName(j) << "\n";
        }

        std::cout << "---\n\n";
    }

    return 0;
}
