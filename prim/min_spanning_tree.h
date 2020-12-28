#pragma once

#include "graph.h"
#include <set>
#include <vector>
#include <list>
// Return minimal spanning tree for the (connected) graph as array of edges.
std::vector<std::pair<int, int>> min_spanning_tree(const Graph &graph);