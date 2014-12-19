#include "processing.hpp"

//////////////
// Includes //
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <tuple>
#include <set>

#include "graph.hpp"

//////////
// Code //

// Generating a random number with a maximum value.
int maxRand(int max) { return rand() % max; }

// Finding all of the connections a given node on a Graph contains.
std::vector<int> findConnections(const Graph& g, const std::set<int>& gotten, int src) {
    std::vector<int> conns;

    for (int i = 0; i < g.getSize(); i++)
        if (i != src && g.connected(src, i) && gotten.count(i) == 0)
            conns.push_back(i);

    return conns;
}

// Finding all of the nodes that haven't been gotten yet.
std::vector<int> notGotten(const Graph& g, const std::set<int>& gotten) {
    std::vector<int> ng;
    for (int i = 0; i < g.getSize(); i++)
        if (gotten.count(i) == 0)
            ng.push_back(i);
    return ng;
}

// Determining the list of pairs for Sinterklaas.
std::vector<std::tuple<int, int>> findPairing(Graph g) {
    std::vector<std::tuple<int, int>> ns;
    std::set<int> gotten;

    std::vector<int> conns;
    int target;

    for (int i = 0; i < g.getSize(); i++) {
        conns = findConnections(g, gotten, i);
        if (conns.size() == 0)
            conns = notGotten(g, gotten);

        if (conns.size() == 0) {
            std::cout << "WHOOPS.\n";
            return ns;
        }
        
        target = conns[maxRand(conns.size())];
        ns.push_back(std::make_tuple(i, target));

        gotten.insert(target);
    }

    return ns;
}

// Printing out the set of pairings.
void printPairing(const Graph& g, std::vector<std::tuple<int, int>> pairs) {
    std::cout << "Pairings!\n";
    for (auto it = pairs.begin(); it != pairs.end(); it++)
        std::cout << " " << g.getName(std::get<0>(*it)) << " got " << g.getName(std::get<1>(*it)) << "!\n";
}
