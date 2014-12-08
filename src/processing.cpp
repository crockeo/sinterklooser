#include "processing.hpp"

//////////
// Code //

// Making a copy of a graph.
Graph* copyGraph(Graph* g) {
    Graph* copy = new Graph(g->getNames(), g->getLength());

    for (int i = 0; i < g->getLength(); i++)
        for (int j = 0; j < g->getLength(); j++)
            if (g->areConnected(i, j))
                copy->connect(i, j);

    return copy;
}

// Determining the list of pairs for Sinterklaas.
std::tuple<int, int>* findPairing(Graph* g) {
    Graph* copy = copyGraph(g);
    delete copy;

    // TODO: Actually do something
    return nullptr;
}
