#ifndef _IO_HPP_
#define _IO_HPP_

//////////////
// Includes //
#include <string>

#include "graph.hpp"

//////////
// Code //

// Loading a graph from a file.
Graph* loadGraph(std::string);

// Writing a graph to an ostream.
void writeGraph(std::ostream out, Graph*);

// Saving a graph to the file system.
void saveGraph(std::string, Graph*);

// Writing a graph to std out.
void coutGraph(Graph*);

#endif
