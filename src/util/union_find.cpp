#include "util/union_find.h"

UnionFind::UnionFind(int num_elements) {
    // start with each set with one element
    num_sets_ = num_elements;
  
    rank_.assign(num_elements, 1);
    set_size_.assign(num_elements, 1);
    
    // assign each elements as its representative
    parent_.assign(num_elements, 0);
    for (int i=0; i < num_elements; ++i)
        parent_[i] = i;
}

int UnionFind::find_set(int element) {
    if (parent_[element] == element)
        return element;

    parent_[element] = find_set(element); // path compression
    return parent_[element];
}

bool UnionFind::same_set(int first, int second) {
    return (find_set(first) == find_set(second));
}

void UnionFind::union_set(int first, int second) {
    int first_set = find_set(first);
    int second_set = find_set(second);
    
    if (first_set != second_set) {
        --num_sets_;

        if (rank_[first_set] > rank_[second_set]) {
            parent_[second_set] = first_set;
            set_size_[first_set] += set_size_[second_set];
        }   
        else {
            parent_[first_set] = second_set;
            set_size_[second_set] += set_size_[first_set];

            if (rank_[first_set] == rank_[second_set]) ++rank_[second_set];
        }
    }
}

int UnionFind::num_sets() { return num_sets_; }

int UnionFind::set_size(int element_from_set) {
    return set_size_[find_set(element_from_set)];
}

