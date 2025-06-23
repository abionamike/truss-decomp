#include "truss.h"
#include "../support/support.h"
#include <queue>
#include <algorithm>

map<Edge, int> truss_decomposition(Graph g) {
    map<Edge, int> support = compute_support(g);
    map<Edge, int> truss_level;

    int k = 2;
    while (true) {
        k++;
        queue<Edge> to_remove;
        set<Edge> in_queue;

        for (auto& [e, s] : support) {
            if (s < k - 2 && truss_level.find(e) == truss_level.end()) {
                to_remove.push(e);
                in_queue.insert(e);
            }
        }

        if (to_remove.empty()) break;

        while (!to_remove.empty()) {
            Edge e = to_remove.front(); to_remove.pop();
            in_queue.erase(e);

            if (truss_level.find(e) != truss_level.end()) continue;

            int u = e.first, v = e.second;
            truss_level[e] = k - 1;
            g[u].erase(v);
            g[v].erase(u);

            vector<int> common;
            set_intersection(
                g[u].begin(), g[u].end(),
                g[v].begin(), g[v].end(),
                back_inserter(common)
            );

            for (int w : common) {
                Edge uw = make_edge(u, w);
                Edge vw = make_edge(v, w);

                if (support.count(uw)) support[uw]--;
                if (support.count(vw)) support[vw]--;

                if (support[uw] < k - 2 && truss_level.find(uw) == truss_level.end() && !in_queue.count(uw)) {
                    to_remove.push(uw);
                    in_queue.insert(uw);
                }
                if (support[vw] < k - 2 && truss_level.find(vw) == truss_level.end() && !in_queue.count(vw)) {
                    to_remove.push(vw);
                    in_queue.insert(vw);
                }
            }
        }
    }

    for (auto& [e, s] : support) {
        if (truss_level.find(e) == truss_level.end()) {
            truss_level[e] = k - 1;
        }
    }

    return truss_level;
}
