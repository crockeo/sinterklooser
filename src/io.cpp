#include "io.hpp"

//////////////
// Includes //
#include <iostream>
#include <fstream>
#include <string>

#include "graph.hpp"

//////////
// Code //

// Loading a graph from a file.
Graph loadGraph(std::string path) {
    std::ifstream in;
    in.open(path);

    if (!in.good())
        return Graph(0, std::vector<std::string>());

    std::string line;
    int len;

    in >> len;
    in >> line;

    if (line.compare("NAMES") != 0) {
        in.close();
        return Graph(0, std::vector<std::string>());
    }

    std::vector<std::string> names = std::vector<std::string>(len);
    for (int i = 0; i < len; i++) {
        in >> line;
        in >> line;

        names[i] = line;
    }

    in >> line;
    if (line.compare("CONNS") != 0) {
        in.close();
        return Graph(0, std::vector<std::string>());
    }

    Graph g(len, names);
    int t1, t2;
    while (!in.eof()) {
        in >> t1;
        in >> t2;

        g.addEdge(t1, t2, 1);
        g.addEdge(t2, t1, 1);
    }

    in.close();
    return g;
}

// Saving a graph to the file system.
int saveGraph(std::string path, const Graph& g) {
    std::ofstream out;
    out.open(path);

    if (!out.good())
        return -1;

    out << g.getSize() << "\n";

    out << "NAMES\n";
    for (int i = 0; i < g.getSize(); i++)
        out << i << " " << g.getName(i) << "\n";

    out << "CONNS\n";
    for (int i = 0; i < g.getSize(); i++)
        for (int j = 0; j < g.getSize(); j++)
            if (g.connected(i, j))
                out << i << " " << j << "\n";

    out.close();

    return 0;
}

// Writing a graph to std out.
int coutGraph(const Graph& g) {
    for (int i = 0; i < g.getSize(); i++) {
        std::cout << g.getName(i) << " knows:\n";
        for (int j = 0; j < g.getSize(); j++) {
            if (i == j)
                continue;
            if (g.connected(i, j))
                std::cout << " - " << g.getName(j) << "\n";
        }

        std::cout << "---\n\n";
    }

    return 0;
}
