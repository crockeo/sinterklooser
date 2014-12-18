#ifndef _IO_HPP_
#define _IO_HPP_

//////////////
// Includes //
#include <string>

#include "graph.hpp"

//////////
// Code //

// Loading a graph from a file.
Graph loadGraph(std::string);

// Saving a graph to the file system.
int saveGraph(std::string, const Graph&);

// Writing a graph to std out.
int coutGraph(const Graph&);

#endif
