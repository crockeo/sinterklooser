//////////////
// Includes //
#include <iostream>

#include "processing.hpp"
#include "graph.hpp"
#include "io.hpp"

//////////
// Code //

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Proper usage: sinterklooser <data file>\n";
        return 1;
    }

    Graph g = loadGraph(std::string(argv[1]));
    if (g.getSize() == 0) {
        std::cerr << "Could not load the file " << argv[1] << "!\n";
        return 2;
    }

    printPairing(g, findPairing(g));

    return 0;
}
