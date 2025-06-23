#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <set>
#include <vector>

using namespace std;

using Edge = pair<int, int>;               // Edge = (u, v)
using Graph = map<int, set<int>>;          // Graph using adjacency list

Edge make_edge(int u, int v);              // Ensures smaller node is first in edge
Graph build_sample_graph();                // Builds sample undirected graph
// void print_truss_levels(const map<Edge, int>& truss); // Print truss results

#endif // GRAPH_H
