#ifndef MST_SOLVER_H
#define MST_SOLVER_H

#include "graph/graph.h"

class MSTSolver {
    protected:
        WeightedDirectedGraph graph_;
        vector<WeightedEdge> mst_;
        int cost_;
    public:
        MSTSolver(WeightedDirectedGraph graph);

        virtual void solve() = 0;
        int getCost();
        vector<WeightedEdge> getMST();
};

#endif