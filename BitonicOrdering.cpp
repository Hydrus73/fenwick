/**
 * This solution to the Bitonic Ordering problem uses my implementation of Fenwick Tree data structure and Coordinate Compression algorithm.
 *
 * https://open.kattis.com/problems/bitonicordering
 */

#include <bits/stdc++.h>

#include "CoordCompression.h"
#include "FenwickTree.h"
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int total_cards;
    std::cin >> total_cards;
    std::vector<int> cards(total_cards);
    for (int i = 0; i < total_cards; i++) {
        std::cin >> cards[i];
    }
    Compressor<int>::OnTheFly compressor(cards);
    std::vector<int> card_locations(total_cards);
    FenwickTree<int> tree(total_cards);
    for (int i = 0; i < total_cards; i++) {
        card_locations[compressor.compress(cards[i])] = i;
        tree.add(i, 1);
    }
    long long swaps = 0;
    for (int i = 0; i < total_cards; i++) {
        int location = card_locations[i];
        swaps += std::min(tree.range_sum(0, location - 1), tree.range_sum(location + 1, total_cards - 1));
        tree.add(location, -1);
    }
    std::cout << swaps << std::endl;
}