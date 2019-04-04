#include <climits>
#include <list>
#include <vector>

#include "graph/graph.h"
#include "util/union_find.h"
#include "algorithms/boruvka.h"

using namespace std;

void Boruvka::solve() {
    UnionFind sets(graph_.get_num_vertices()); // respresenting the sets of vertices formed
    list<WeightedEdge> inter_sets; // edges between different sets

    // initilize inter_sets with all edges
    for (int i=0; graph_.get_num_vertices(); ++i) {
        vector<WeightedEdge> out = graph_.edgesFrom(i);
        for(auto it = out.begin(); it != out.end(); ++it)
            inter_sets.push_back(*it); 
    }

    // start algorithm main loop
    cost_ = 0;
    mst_.clear();
    while (sets.num_sets() > 1) {
        vector<WeightedEdge*> cheapest_edge;
        cheapest_edge.assign(sets.num_sets(), NULL);

        // find the cheapest edge outbound from each set
        for (auto it = inter_sets.begin(); it != inter_sets.end(); ++it) {
            if (!sets.same_set(it->from, it->to)) {
                /* check if this edge is cheaper than the current cheapest
                   for each set and update if needed */
                int from_set = sets.find_set(it->from); // set of the origin
                if (cheapest_edge[from_set] == NULL ||
                    it->weight < cheapest_edge[from_set]->weight)
                    cheapest_edge[from_set] = &(*it);

                int to_set = sets.find_set(it->to); // set of the destination
                if(cheapest_edge[to_set] == NULL ||
                    it->weight < cheapest_edge[to_set]->weight)
                    cheapest_edge[to_set] = &(*it);
            }
            else { 
                /* if it doesn't connect different edges, no further iteration
                   will used it */
                inter_sets.erase(it);
            }
        }

        // connect the sets using the cheapest edges for each set
        WeightedEdge *cheapest;
        for (int i = 0; i < graph_.get_num_vertices(); ++i) {
            cheapest = cheapest_edge[sets.find_set(i)];

            if(!sets.same_set(cheapest->from, cheapest->to)) {
                sets.union_set(cheapest->from, cheapest->to);
                
                mst_.emplace_back(cheapest);
                cost_ += cheapest->weight;
            }
        }
    }
}
