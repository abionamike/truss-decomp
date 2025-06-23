#include "graph/graph.h"
#include "truss/truss.h"
#include "support/support.h"

#include <iostream>

int main() {
    Graph g = build_sample_graph();

    auto support = compute_support(g);
    std::cout << "Initial support counts per edge:\n";
    for (const auto& [e, s] : support) {
        std::cout << "(" << e.first << "," << e.second << "): " << s << "\n";
    }

    auto truss = truss_decomposition(g);
    // print_truss_levels(truss);

    return 0;
}
