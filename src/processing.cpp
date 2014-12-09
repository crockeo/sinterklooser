#include "processing.hpp"

//////////////
// Includes //
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <tuple>

#include "node.hpp"

//////////
// Code //

using std::make_tuple;
using std::vector;
using std::tuple;
using std::get;

// Getting a random number with a max value.
int randMax(int n) { return rand() % n; }

// Making a copy of a graph.
Graph* copyGraph(Graph* g) {
    Graph* copy = new Graph(g->getNames(), g->getLength());

    for (int i = 0; i < g->getLength(); i++)
        for (int j = 0; j < g->getLength(); j++)
            if (g->areConnected(i, j))
                copy->connect(i, j);

    return copy;
}

// Creating an array of nodes that are connected to another node.
std::vector<int> findNodes(Graph* g, int i) {
    std::vector<int> nodes;

    for (int j = 0; j < g->getLength(); j++)
        if (g->areConnected(i, j))
            nodes.push_back(j);

    return nodes;
}

// Determining the list of pairs for Sinterklaas.
std::vector<std::tuple<int, int>> findPairing(Graph* g) {
    Graph* copy = copyGraph(g);

    std::vector<std::tuple<int, int>> pairs;
    for (int i = 0; i < copy->getLength(); i++) {
        std::vector<int> nodes = findNodes(g, i);

        pairs.push_back(make_tuple(i, nodes[randMax(nodes.size())]));

        for (int j = 0; j < copy->getLength(); j++)
            copy->disconnect(i, j);
    }

    delete copy;
    return pairs;
}

// Printing out the set of pairings.
void printPairing(Graph* g, std::vector<std::tuple<int, int>> pairs) {
    std::cout << "Pairing list:\n";
    for (int i = 0; i < pairs.size(); i++)
        std::cout << "  " << g->getName(get<0>(pairs[i])) << " gets " << g->getName(get<1>(pairs[i])) << "!\n";
}
