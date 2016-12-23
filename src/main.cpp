//////////////
// Includes //
#include <iostream>
#include <cstdlib>

#include "processing.hpp"
#include "new_file.hpp"
#include "graph.hpp"
#include "io.hpp"

//////////
// Code //

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2 || argc > 3 || (argc == 3 && strcmp(argv[1], "newfile"))) {
        cerr << "Proper usage: sinterklooser ['newfile'] <data file>" << endl;
        return 1;
    }

    srand(time(nullptr));
    Graph *g = nullptr;
    if (argc == 2)
        g = loadGraph(std::string(argv[1]));
    else if (argc == 3)
        g = loadNewFile(std::string(argv[2]));
    
    if (g == nullptr) {
        std::cerr << "Could not load the file " << argv[1] << endl;
        return 2;
    }

    printPairing(g, findPairing(g));
    delete g;
    return 0;
}
