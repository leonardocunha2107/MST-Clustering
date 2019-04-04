#ifndef PRIM_H
#define PRIM_H

#include <unordered_set>

#include "graph/graph.h"
#include "algorithms/mst_solver.h"

using namespace std;


class Prim : public MSTSolver {
    private:
        unordered_set<int> not_annexed;

    public:
        Prim(WeightedDirectedGraph graph);

        void connected_solve(int start);
        void solve();
};

#endif