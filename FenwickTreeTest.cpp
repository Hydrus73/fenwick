#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <bits/stdc++.h>

#include "FenwickTree.h"
#include "doctest.h"
using namespace std;
TEST_CASE("Testing the Fenwick Tree") {
    FenwickTree<long long> tree(10);
    long long current_sum = 0;
    for (int i = 0; i < 10; i++) {
        tree.add(i, i * 1000000000LL);
        current_sum += i * 1000000000LL;
        CHECK(tree.partial_sum(9) == current_sum);
        CHECK(tree.range_sum(0, 9) == current_sum);
        CHECK(tree.range_sum(i, i) == i * 1000000000LL);
    }
    for (int i1 = 0; i1 < 10; i1++) {
        for (int i2 = i1 + 1; i2 < 10; i2++) {
            CHECK(tree.range_sum(i1, i2) == ((i2 * (i2 + 1) / 2) - (i1 * (i1 - 1) / 2)) * 1000000000LL);
        }
    }
    tree.add(5, -1);
    for (int i1 = 0; i1 < 10; i1++) {
        for (int i2 = i1 + 1; i2 < 10; i2++) {
            CHECK(tree.range_sum(i1, i2) == ((i2 * (i2 + 1) / 2) - (i1 * (i1 - 1) / 2)) * 1000000000LL - (i1 <= 5 && i2 >= 5));
        }
    }
}