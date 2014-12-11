#include "processing.hpp"

//////////////
// Includes //
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <vector>
#include <tuple>
#include <set>

#include "digraph.hpp"

//////////
// Code //

// Getting a random number with some cap.
int randMax(int n) {
    if (n <= 0)
        std::cout << "TRYING TO RAND <= 0!!!\n";
    return rand() % n;
}

// Making a copy of a Digraph.
Digraph copyDigraph(Digraph* const g) {
    Digraph copy(g->getNames());

    std::set<Edge> edges = g->getEdges();
    for (auto it = edges.begin(); it != edges.end(); it++)
        copy.connect(it->src, it->dst, it->weight);

    return copy;
}

// Getting a set of edges from a digraph with a source n.
std::vector<Edge> getEdges(Digraph g, std::set<int> selected, int src) {
    std::set<Edge> gEdges = g.getEdges();
    std::vector<Edge> edges;

    for (auto it = gEdges.begin(); it != gEdges.end(); it++)
        if (it->src == src && selected.count(it->dst) == 0)
            edges.push_back(*it);

    return edges;
}

// Sorting a vector of edges by weight (in descending order).
std::vector<Edge> sortEdges(std::vector<Edge> edges) {
    std::sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight;
    });

    return edges;
}

// Getting the number of maximum weights from an edge.
int maxNum(std::vector<Edge> edges) {
    for (int j = 0; j < edges.size(); j++)
        if (edges[j].weight != edges[0].weight)
            return j + 1;
    return edges.size();
}

// Finding open spots.
std::vector<int> findOpens(std::set<int> edges, int curr, int len) {
    std::vector<int> opens;
    for (int i = 0; i < len; i++)
        if (i != curr && edges.count(i) == 0)
            opens.push_back(i);
    return opens;
}

// Determining the list of pairs for Sinterklaas.
std::vector<std::tuple<int, int>> findPairing(Digraph* const graph) {
    Digraph copy = copyDigraph(graph);
    std::set<Edge> origEdges = copy.getEdges();

    int len = copy.getNames().size();
    std::set<int> selected;
    std::vector<std::tuple<int, int>> pairs;
    for (int i = 0; i < len; i++) {
        std::vector<Edge> edges = getEdges(copy, selected, i);
        std::vector<Edge> sorted = sortEdges(edges);
        int max = maxNum(sorted);

        Edge selEdge(0, 0, 0);
        if (max == 0) {
            std::vector<int> opens = findOpens(selected, i, len);
            if (opens.size() == 0)
                continue;

            selEdge = Edge(i, opens[randMax(opens.size())], 0);
        } else
            selEdge = edges[randMax(maxNum(sortEdges(edges)))];

        pairs.push_back(std::make_tuple(selEdge.src, selEdge.dst));
        selected.insert(selEdge.dst);
    }

    return pairs;
}

// Printing out the set of pairings.
void printPairing(Digraph* graph, std::vector<std::tuple<int, int>> pairs) {
    std::cout << "Pairing list:\n";
    for (auto it = pairs.begin(); it != pairs.end(); it++)
        std::cout << " "
                  << graph->getName(std::get<0>(*it))
                  << " gets "
                  << graph->getName(std::get<1>(*it))
                  << "\n";
}
