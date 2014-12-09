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
    std::string* names = new std::string[len];

    names[0] = "Cerek";
    names[1] = "Jibben";
    names[2] = "Remer";
    names[3] = "Monique";
    names[4] = "Michael";

    Graph* g = new Graph(names, len);
    delete[] names;

    for (int i = 0; i < g->getLength(); i++)
        for (int j = 0; j < g->getLength(); j++)
            if (i != j)
                g->connect(i, j);

    coutGraph(g);

    delete g;
}

void loadGraph() {
    std::cout << "TEST 02\n";
    std::string path = "examples/data01.txt";

    Graph* g = loadGraph(path);

    if (g != nullptr) {
        coutGraph(g);
        delete g;
    } else {
        std::cerr << "Could not load '" << path << "'!\n";
    }
}

void testProcess() {
    std::cout << "TEST 03\n";
    std::string path = "examples/data02.txt";

    Graph* g = loadGraph(path);

    if (g == nullptr) {
        std::cerr << "Could ont load " << path << "!\n";
        return;
    }

    printPairing(g, findPairing(g));

    delete g;
}

int main() {
    // Testing some stuff about the graph.
    testGraph();

    // Testing loading a graph from the file system.
    loadGraph();

    // Testing processing a graph from the file system.
    testProcess();
}
