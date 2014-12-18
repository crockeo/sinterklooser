#include "processing.hpp"

//////////////
// Includes //
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <tuple>
#include <set>

#include "graph.hpp"
#include "node.hpp"

//////////
// Code //

using std::make_tuple;
using std::vector;
using std::tuple;
using std::get;
using std::set;

// Getting a random number with a max value.
int randMax(int n) { return rand() % n; }

// Creating an array of nodes that are connected to another node.
std::vector<int> findNodes(const Graph& g, int i) {
    std::vector<int> nodes;

    for (int j = 0; j < g.getSize(); j++)
        if (g.connected(i, j))
            nodes.push_back(j);

    return nodes;
}

vector<int> findOpen(const Graph& g, std::set<int> gotten) {
    vector<int> opens;

    for (int i = 0; i < g.getSize(); i++)
        if (gotten.count(i) == 0)
            opens.push_back(i);

    return opens;
}

// Determining the list of pairs for Sinterklaas.
std::vector<std::tuple<int, int>> findPairing(Graph g) {
    std::vector<std::tuple<int, int>> pairs;
    std::set<int> gotten;
    for (int i = 0; i < g.getSize(); i++) {
        std::vector<int> nodes = findNodes(g, i);
        int target;

        if (nodes.size() == 0) {
            std::vector<int> opens = findOpen(g, gotten);
            target = opens[randMax(opens.size())];
        } else
            target = nodes[randMax(nodes.size())];

        pairs.push_back(make_tuple(i, target));
        gotten.insert(target);

        g.removeEdge(target, i);
        for (int j = 0; j < g.getSize(); j++)
            g.removeEdge(j, target);
    }

    return pairs;
}

// Printing out the set of pairings.
void printPairing(const Graph& g, std::vector<std::tuple<int, int>> pairs) {
    std::cout << "Pairing list:\n";
    for (int i = 0; i < pairs.size(); i++)
        std::cout << "  " << g.getName(get<0>(pairs[i])) << " gets " << g.getName(get<1>(pairs[i])) << "!\n";
}
