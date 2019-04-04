#include <algorithm>

#include "util/union_find.h"
#include "algorithms/kruskal.h"

void Kruskal::solve() {
    UnionFind sets(graph_.get_num_vertices());
    vector<WeightedEdge> all_edges;

    // initilize vector with edges
    vector<WeightedEdge> out;
    for(int i=0; i < graph_.get_num_vertices(); ++i) {
        out = graph_.edgesFrom(i);
        for(auto it = out.begin(); it != out.end(); ++it)
            all_edges.push_back(*it);
    }

    // sort this vector
    sort(all_edges.begin(), all_edges.end());

    WeightedEdge curr; // auxiliar edge
    int num_chosen_edges = 0;
    int i = 0;
    while(i < graph_.get_num_edges() && 
          num_chosen_edges < graph_.get_num_vertices()-1) {
        curr = all_edges[i++];
        if (!sets.same_set(curr.from, curr.to)) {
            ++num_chosen_edges;
            sets.union_set(curr.from, curr.to);

            mst_.emplace_back(curr);
            cost_ += curr.weight;
        }
    }
}