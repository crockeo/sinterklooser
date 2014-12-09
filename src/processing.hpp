#ifndef _PROCESSING_HPP_
#define _PROCESSING_HPP_

//////////////
// Includes //
#include <vector>
#include <tuple>

#include "graph.hpp"

//////////
// Code //

// Determining the list of pairs for Sinterklaas.
std::vector<std::tuple<int, int>> findPairing(Graph*);

// Printing out the set of pairings.
void printPairing(Graph*, std::vector<std::tuple<int, int>>);

#endif
