//////////////
// Includes //
#include <iostream>
#include <vector>
#include <tuple>

#include "processing.hpp"
#include "graph.hpp"
#include "io.hpp"

//////////
// Code //

void testGraph() {
    std::cout << "TEST 01\n";
    int len = 5;
    std::vector<std::string> names;

    names.push_back("Cerek");
    names.push_back("Jibben");
    names.push_back("Remer");
    names.push_back("Monique");
    names.push_back("Michael");

    Graph g(len, names);
    for (int i = 0; i < g.getSize(); i++) {
        for (int j = 0; j < g.getSize(); j++) {
            if (i != j) {
                g.addEdge(i, j, 1);
                g.addEdge(j, i, 1);
            }
        }
    }

    coutGraph(g);
}

void loadGraph() {
    std::cout << "TEST 02\n";
    std::string path = "examples/data02.txt";

    Graph g = loadGraph(path);

    if (g.getSize() > 0) {
        coutGraph(g);
    } else {
        std::cerr << "Could not load '" << path << "'!\n";
    }
}

void testProcess() {
    std::cout << "TEST 03\n";
    std::string path = "examples/data01.txt";

    Graph g = loadGraph(path);

    if (g.getSize() == 0) {
        std::cerr << "Could not load " << path << "!\n";
        return;
    }

    printPairing(g, findPairing(g));
}

int main() {
    // Testing some stuff about the graph.
    testGraph();

    // Testing loading a graph from the file system.
    loadGraph();

    // Testing processing a graph from the file system.
    testProcess();
}
