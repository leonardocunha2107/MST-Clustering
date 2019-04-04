#ifndef BORUVKA_H
#define BORUVKA_H

#include "graph/graph.h"
#include "algorithms/mst_solver.h"

class Boruvka : public MSTSolver {
    public:
        Boruvka(WeightedDirectedGraph graph) : MSTSolver(graph) { }

        void solve();
};

#endif