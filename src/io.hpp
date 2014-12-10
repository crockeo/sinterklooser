#ifndef _IO_HPP_
#define _IO_HPP_

//////////////
// Includes //
#include <string>

#include "digraph.hpp"

//////////
// Code //

// Loading a graph from a file.
Digraph* loadDigraph(std::string);

// Saving a graph to the file system.
int saveDigraph(std::string, Digraph*);

// Writing a graph to std out.
int coutDigraph(Digraph*);

#endif
