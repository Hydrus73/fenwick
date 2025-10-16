/**
 * This is an adaptable version of the Fenwick Tree data structure for any type of number. It has features for range sums and updating values at a certain index.
 */

#include <bits/stdc++.h>
template <typename Number>
class FenwickTree {
   public:
    std::vector<Number> tree;
    FenwickTree(int size) {
        tree = std::vector<Number>(size, 0);
    }
    void add(unsigned i, Number num) {
        while (i < tree.size()) {
            tree[i] += num;
            i |= (i + 1);
        }
    }
    Number partial_sum(int i) {
        Number total = 0;
        while (i >= 0) {
            total += tree[i];
            i = (i & (i + 1)) - 1;
        }
        return total;
    }
    Number range_sum(int i, int j) {
        return partial_sum(j) - partial_sum(i - 1);
    }
};