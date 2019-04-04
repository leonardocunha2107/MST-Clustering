#include "graph/weighted_directed_graph.h"

WeightedDirectedGraph::WeightedDirectedGraph(int num_vertices) : 
num_vertices_(num_vertices), outbound_(num_vertices), inbound_(num_vertices) {
    num_edges_ = 0;
}

void WeightedDirectedGraph::addEdge(int from, int to, int weight) {
    outbound_[from].emplace_back(from, to, weight);
    inbound_[to].emplace_back(from, to, weight);
}

vector<WeightedEdge> WeightedDirectedGraph::edgesFrom(int vertice) {
    return outbound_[vertice];
}

vector<WeightedEdge> WeightedDirectedGraph::edgesTo(int vertice) {
    return inbound_[vertice];
}

int WeightedDirectedGraph::get_num_vertices() { return num_vertices_; }

int WeightedDirectedGraph::get_num_edges() { return num_edges_; }
