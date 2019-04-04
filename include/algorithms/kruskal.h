#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "graph/graph.h"
#include "algorithms/mst_solver.h"

class Kruskal : public MSTSolver { 
    public:
        Kruskal(WeightedDirectedGraph graph) : MSTSolver(graph) { }

        void solve();
};

#endif