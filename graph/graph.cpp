#include "graph.h"
#include <iostream>
#include <algorithm>

// 1
// / \
// 2---3
// \ /
//  4
// / \
// 5---6

// {1,2}, {1,3}, {1,4},
// {2,3}, {2,4},
// {3,4},
// {4,5}, {4,6},
// {5,6}

Edge make_edge(int u, int v) {
    return (u < v) ? make_pair(u, v) : make_pair(v, u);
}

Graph build_sample_graph() {
    Graph g;
    vector<Edge> edges = {
        {1,2}, {1,3}, {2,3},       
        {2,4}, {3,4},              
        {4,5}, {4,6}, {5,6}    
    };

    for (const auto& [u, v] : edges) {
        g[u].insert(v);
        g[v].insert(u);
    }

    return g;
}

// void print_truss_levels(const map<Edge, int>& truss) {
//     cout << "\nFinal Truss Levels:\n";
//     for (const auto& [e, level] : truss) {
//         cout << "(" << e.first << "," << e.second << "): " << level << "\n";
//     }
// }
