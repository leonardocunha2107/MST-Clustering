#include <queue>

#include "algorithms/prim.h"

using namespace std;


Prim::Prim(WeightedDirectedGraph graph) : MSTSolver(graph) {
    for(int i=0; i < graph.get_num_vertices(); ++i)
        not_annexed.insert(i);
}

void Prim::solve() {
    cost_ = 0;

    while(!not_annexed.empty())
        connected_solve(*not_annexed.begin());
}

void Prim::connected_solve(int start) {
    vector<WeightedEdge> out; // auxiliar edge vector
    priority_queue<WeightedEdge> out_queue; // outbound edges of this component

    // initialize by annexing the vertice start
    not_annexed.erase(start);
    out = graph_.edgesFrom(start);
    for (auto it = out.begin(); it != out.end(); ++it) {
        if (not_annexed.count(it->to) > 0)
            out_queue.emplace(*it); 
    }
    
    // start algorithm
    WeightedEdge curr; // auxiliar edge
    while (!out_queue.empty()) {
        curr = out_queue.top(); // get edge with minimal weight
        out_queue.pop();

        if (not_annexed.count(curr.to) > 0) {
        // if the destination is not annexed, annex it
            not_annexed.erase(curr.to);
            mst_.emplace_back(curr);
            cost_ += curr.weight;

            out = graph_.edgesFrom(curr.to);
            for (auto it = out.begin(); it != out.end(); ++it) {
                if (not_annexed.count(it->to) > 0)
                    out_queue.emplace(*it);
            }
        }
    }
}