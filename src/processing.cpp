#include "processing.hpp"

//////////////
// Includes //
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <tuple>
#include <set>

#include "digraph.hpp"

//////////
// Code //

// Making a copy of a Digraph.
Digraph* const copyGraph(Digraph* const g) {
    Digraph* const copy = new Digraph(g->getNames());

    std::set<Edge> edges = g->getEdges();
    for (auto it = edges.begin(); it != edges.end(); it++)
        copy->connect(it->src, it->dst, it->weight);

    return copy;
}

// Determining the list of pairs for Sinterklaas.
std::vector<std::tuple<int, int>> findPairing(Digraph* graph) {
    std::vector<std::tuple<int, int>> pairs;
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

//using std::make_tuple;
//using std::vector;
//using std::tuple;
//using std::get;
//using std::set;

//// Getting a random number with a max value.
//int randMax(int n) { return rand() % n; }

//// Making a copy of a graph.
//Graph* copyGraph(Graph* g) {
    //Graph* copy = new Graph(g->getNames(), g->getLength());

    //for (int i = 0; i < g->getLength(); i++)
        //for (int j = 0; j < g->getLength(); j++)
            //if (g->areConnected(i, j))
                //copy->connect(i, j);

    //return copy;
//}

//// Creating an array of nodes that are connected to another node.
//std::vector<int> findNodes(Graph* g, int i) {
    //std::vector<int> nodes;

    //for (int j = 0; j < g->getLength(); j++)
        //if (g->areConnected(i, j))
            //nodes.push_back(j);

    //return nodes;
//}

//vector<int> findOpen(Graph* g, std::set<int> gotten) {
    //vector<int> opens;

    //for (int i = 0; i < g->getLength(); i++)
        //if (gotten.count(i) == 0)
            //opens.push_back(i);

    //return opens;
//}

//// Determining the list of pairs for Sinterklaas.
//std::vector<std::tuple<int, int>> findPairing(Graph* g) {
    //Graph* copy = copyGraph(g);

    //std::vector<std::tuple<int, int>> pairs;
    //std::set<int> gotten;
    //for (int i = 0; i < copy->getLength(); i++) {
        //std::vector<int> nodes = findNodes(copy, i);
        //int target;

        //if (nodes.size() == 0) {
            //std::vector<int> opens = findOpen(copy, gotten);
            //target = opens[randMax(opens.size())];
        //} else
            //target = nodes[randMax(nodes.size())];

        //pairs.push_back(make_tuple(i, target));
        //gotten.insert(target);

        //copy->disconnectDir(target, i);
        //for (int j = 0; j < copy->getLength(); j++)
            //copy->disconnectDir(j, target);
    //}

    //delete copy;
    //return pairs;
//}

//// Printing out the set of pairings.
//void printPairing(Graph* g, std::vector<std::tuple<int, int>> pairs) {
    //std::cout << "Pairing list:\n";
    //for (int i = 0; i < pairs.size(); i++)
        //std::cout << "  " << g->getName(get<0>(pairs[i])) << " gets " << g->getName(get<1>(pairs[i])) << "!\n";
//}
