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
    std::ofstream out;
    out.open(path);

    if (!out.good())
        return -1;

    out << g->getLength() << "\n";

    out << "NAMES\n";
    for (int i = 0; i < g->getLength(); i++)
        out << i << " " << g->getName(i) << "\n";

    out << "CONNS\n";
    for (int i = 0; i < g->getLength(); i++)
        for (int j = 0; j < g->getLength(); j++)
            if (g->areConnected(i, j))
                out << i << " " << j << "\n";

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
