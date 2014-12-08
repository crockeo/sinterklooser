//////////////
// Includes //
#include <iostream>

#include "graph.hpp"
#include "io.hpp"

//////////
// Code //

void testGraph() {
    int len = 5;
    std::string* names = new std::string[len];

    names[0] = "Cerek";
    names[1] = "Jibben";
    names[2] = "Remer";
    names[3] = "Monique";
    names[4] = "Michael";

    Graph* g = new Graph(names, len);
    delete[] names;

    g->connect(1, 2);
    g->connect(0, 3);
    g->connect(3, 4);

    coutGraph(g);

    delete g;
}

int main() {
    // Testing some stuff about the graph.
    testGraph();

    std::cout << "Hello world!\n";
}
