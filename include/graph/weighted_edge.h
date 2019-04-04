#ifndef WEIGHTED_EDGE_H
#define WEIGHTED_EDGE_H

struct WeightedEdge {
    int from;
    int to;
    int weight;
};

bool operator<(const WeightedEdge& a, const WeightedEdge& b) {
    return a.weight > b.weight;
}

#endif