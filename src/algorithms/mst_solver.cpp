
#include "algorithms/mst_solver.h"

using namespace std;


MSTSolver::MSTSolver(WeightedDirectedGraph graph) : graph_(graph) {
    cost_ = 0;
}
int MSTSolver::getCost() { return cost_; }

vector<WeightedEdge> MSTSolver::getMST() { return mst_; }
