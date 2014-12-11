#include "io.hpp"

//////////////
// Includes //
#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include "digraph.hpp"

//////////
// Code //

// Loading a graph from a file.
Digraph* loadDigraph(std::string path) {
    std::ifstream in(path);

    if (!in.good())
        return nullptr;

    std::string line;
    int len;
    int src, dst, weight;

    // Reading in the file header.
    in >> line;
    if (line.compare("SS") != 0)
        return nullptr;

    // Getting the length.
    in >> len;

    // Reading in the NAMES header.
    in >> line;
    if (line.compare("NAMES") != 0)
        return nullptr;

    // Reading in the names.
    std::vector<std::string> names;
    for (int i = 0; i < len; i++) {
        in >> line;
        names.push_back(line);
    }

    Digraph* graph = new Digraph(names);

    // Reading in the CONNS header.
    in >> line;
    if (line.compare("CONNS") != 0)
        return nullptr;

    // Reading in the connections.
    while (!in.eof()) {
        in >> src;
        in >> dst;
        in >> weight;

        graph->connect(src, dst, weight);
    }

    return graph;
}

// Saving a graph to the file system.
int saveDigraph(std::string path, Digraph* graph) {
    std::ofstream out(path);

    if (!out.good())
        return -1;

    // Writing the header.
    out << "SS\n";

    // Writing the size.
    out << graph->getNames().size() << "\n";

    // Writing the names header.
    out << "NAMES\n";

    // Writing then names
    for (int i = 0; i < graph->getNames().size(); i++)
        out << graph->getName(i) << "\n";

    // Writing the connections header.
    out << "CONNS\n";

    // Writing the connections.
    std::set<Edge> edges = graph->getEdges();
    for (std::set<Edge>::iterator it = edges.begin(); it != edges.end(); it++)
        out << it->src << " " << it->dst << " " << it->weight << "\n";

    return 0;
}

// Writing a graph to std out.
int coutDigraph(Digraph* graph) {
    std::set<Edge> edges = graph->getEdges();

    std::cout << "Graph report!\n";
    for (std::set<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {
        Edge e = *it;

        std::cout << " "             << graph->getName(e.src)
                  << " knows "       << graph->getName(e.dst)
                  << " with weight " << e.weight
                  << "!\n";
    }

    return 0;
}
