#ifndef UNION_FIND_H
#define UNION_FIND_H

/* 
    This implementation of the Union Find data structure is inspired by the
book "Competitive Programming 3: The New Lower Bound of Programming Contests",
written by Steven Halim. The original implementation can be found at
https://github.com/stevenhalim/cpbook-code.
*/
#include <vector>

using namespace std;

class UnionFind {
    private:
        vector<int> parent_, rank_, set_size_;
        int num_sets_;
    public:
        UnionFind(int num_elements);

        int find_set(int element);
        bool same_set(int first, int second);
        void union_set(int first, int second);
        int num_sets();
        int set_size(int element_from_set);
};

#endif