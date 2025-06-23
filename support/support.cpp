#include "support.h"
#include <algorithm>

// Support is number of triangles an edge is involved in
map<Edge, int> compute_support(Graph& g) {
    map<Edge, int> support;

    for (auto& [u, neighbors_u] : g) {
        for (int v : neighbors_u) {
            if (u < v) {
                set<int> common;
                set_intersection(
                    g[u].begin(), g[u].end(),
                    g[v].begin(), g[v].end(),
                    inserter(common, common.begin())
                );
                support[make_edge(u, v)] = common.size();
            }
        }
    }

    return support;
}
