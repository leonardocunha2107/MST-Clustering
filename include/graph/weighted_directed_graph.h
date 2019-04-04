#ifndef WEIGHTED_DIRECTED_GRAPH_H
#define WEIGHTED_DIRECTED_GRAPH_H

#include <vector>

#include "graph/weighted_edge.h"

using namespace std;


class WeightedDirectedGraph {
    private:
        int num_vertices_, num_edges_;
        vector<vector<WeightedEdge>> outbound_, inbound_;

    public:
        WeightedDirectedGraph(int num_vertices);

        void addEdge(int from, int to, int weight);
        vector<WeightedEdge> edgesFrom(int vertice);
        vector<WeightedEdge> edgesTo(int vertice);
        int get_num_vertices();
        int get_num_edges();
};

#endif