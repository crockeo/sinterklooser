//////////////
// Includes //
#include <iostream>
#include <vector>
#include <tuple>

#include "processing.hpp"
#include "digraph.hpp"
#include "io.hpp"

//////////
// Code //

void testDigraph() {
    std::cout << "TEST 01\n";
    int len = 5;
    std::vector<std::string> names;

    names.push_back("Cerek");
    names.push_back("Jibben");
    names.push_back("Remer");
    names.push_back("Monique");
    names.push_back("Michael");

    Digraph* g = new Digraph(names);

    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            if (i != j)
                g->connectBoth(i, j, 3);
    coutDigraph(g);

    delete g;
}

void loadDigraph() {
    std::cout << "TEST 02\n";
    std::string path = "examples/data02.txt";

    Digraph* g = loadDigraph(path);

    if (g != nullptr) {
        coutDigraph(g);
        delete g;
    } else {
        std::cerr << "Could not load '" << path << "'!\n";
    }
}

void testProcess() {
    std::cout << "TEST 03\n";
    std::string path = "examples/data01.txt";

    Digraph* g = loadDigraph(path);

    if (g == nullptr) {
        std::cerr << "Could ont load " << path << "!\n";
        return;
    }

    printPairing(g, findPairing(g));

    delete g;
}

int main() {
    // Testing some stuff about the graph.
    testDigraph();

    // Testing loading a graph from the file system.
    loadDigraph();

    // Testing processing a graph from the file system.
    testProcess();
}
