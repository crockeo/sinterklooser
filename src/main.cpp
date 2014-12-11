//////////////
// Includes //
#include <iostream>

#include "processing.hpp"
#include "digraph.hpp"
#include "io.hpp"

//////////
// Code //

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Proper usage: sinterklooser <data file>\n";
        return 1;
    }

    Digraph* g = loadDigraph(std::string(argv[1]));
    
    if (g == nullptr) {
        std::cerr << "Could not load the file " << argv[1] << "!\n";
        return 2;
    }

    auto pairing = findPairing(g);
    if (pairing.size() == 0)
        std::cout << "There were no pairings found!\n";
    else
        printPairing(g, pairing);

    delete g;
    return 0;
}
