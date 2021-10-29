#include <bits/stdc++.h>

using namespace std;
const int maxn = 200;

array<array<bool, n>, n> visited;

void f_fill(ll x, ll y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (visited[x][y]) return;

    visited[x][y] = true;

    f_fill(x + 1, y);
    f_fill(x - 1, y);
    f_fill(x, y + 1);
    f_fill(x, y - 1);
}