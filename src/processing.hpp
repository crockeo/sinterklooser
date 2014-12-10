#ifndef _PROCESSING_HPP_
#define _PROCESSING_HPP_

//////////////
// Includes //
#include <vector>
#include <tuple>

#include "digraph.hpp"

//////////
// Code //

// Determining the list of pairs for Sinterklaas.
std::vector<std::tuple<int, int>> findPairing(Digraph*);

// Printing out the set of pairings.
void printPairing(Digraph*, std::vector<std::tuple<int, int>>);

#endif
