/**
 * This solution to the Juggler problem uses my implementation of Fenwick Tree data structure.
 *
 * https://open.kattis.com/problems/juggler
 */

#include <bits/stdc++.h>

#include "FenwickTree.h"
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int total_balls;
    std::cin >> total_balls;
    std::vector<int> ball_locations(total_balls);
    FenwickTree<int> tree(total_balls);
    for (int i = 0; i < total_balls; i++) {
        int ball;
        std::cin >> ball;
        ball_locations[--ball] = i;
        tree.add(i, 1);
    }
    long long moves = total_balls;
    int position = 0;
    for (int ball : ball_locations) {
        if (ball < position) {
            moves += std::min(tree.range_sum(ball, position - 1), tree.range_sum(position, ball_locations.size() - 1) + tree.range_sum(0, ball) - 1);
        } else if (ball > position) {
            moves += std::min(tree.range_sum(position, ball) - 1, tree.range_sum(0, position - 1) + tree.range_sum(ball, ball_locations.size() - 1));
        }
        position = ball;
        tree.add(ball, -1);
    }
    std::cout << moves << std::endl;
}