#include "io.hpp"

//////////////
// Includes //
#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include "digraph.hpp"

//////////
// Code //


// Loading a graph from a file.
Digraph* loadDigraph(std::string path) {
    return nullptr;
}

// Saving a graph to the file system.
int saveDigraph(std::string path, Digraph* graph) {
    std::ofstream out(path);

    if (!out.good())
        return -1;

    out << graph->getNames().size() << "\n";

    out << "NAMES\n";
    for (int i = 0; i < graph->getNames().size(); i++)
        out << graph->getName(i) << "\n";

    out << "CONNS\n";
    std::set<Edge> edges = graph->getEdges();
    for (std::set<Edge>::iterator it = edges.begin(); it != edges.end(); it++)
        out << it->src << " " << it->dst << " " << it->weight << "\n";

    return 0;
}

// Writing a graph to std out.
int coutDigraph(Digraph* graph) {
    std::set<Edge> edges = graph->getEdges();
    
    std::cout << "Graph report!\n";
    for (std::set<Edge>::iterator it = edges.begin(); it != edges.end(); it++) {
        Edge e = *it;

        std::cout << " "             << graph->getName(e.src)
                  << " knows "       << graph->getName(e.dst)
                  << " with weight " << e.weight
                  << "!\n";
    }

    return 0;
}

//// Loading a graph from a file.
//Graph* loadGraph(std::string path) {
    //std::ifstream in;
    //in.open(path);

    //if (!in.good())
        //return nullptr;

    //std::string line;
    //int len;

    //in >> len;
    //in >> line;

    //if (line.compare("NAMES") != 0) {
        //in.close();
        //return nullptr;
    //}

    //std::string* names = new std::string[len];
    //for (int i = 0; i < len; i++) {
        //in >> line;
        //in >> line;

        //names[i] = line;
    //}

    //in >> line;
    //if (line.compare("CONNS") != 0) {
        //in.close();
        //delete[] names;
        //return nullptr;
    //}

    //Graph* g = new Graph(names, len);

    //int t1, t2;
    //while (!in.eof()) {
        //in >> t1;
        //in >> t2;

        //g->connect(t1, t2);
    //}

    //in.close();
    //return g;
//}

//// Writing a graph to std out.
//int coutGraph(Graph* g) {
    //for (int i = 0; i < g->getLength(); i++) {
        //std::cout << g->getName(i) << " knows:\n";
        //for (int j = 0; j < g->getLength(); j++) {
            //if (i == j)
                //continue;
            //if (g->areConnected(i, j))
                //std::cout << " - " << g->getName(j) << "\n";
        //}

        //std::cout << "---\n\n";
    //}

    //return 0;
//}
