#ifndef _NEW_FILE_HPP_
#define _NEW_FILE_HPP_

//////////////
// Includes //
#include <string>

#include "graph.hpp"

//////////
// Code //

// Loading a new file. Parses by group and automatically connects each person
// within a group.
Graph *loadNewFile(std::string path);

#endif
