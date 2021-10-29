#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

set<int> adj[maxn];
bool visited[maxn]{false};

int dfs(int node) {
    if(visited[node]) return -1;
    visited[node] = true;

    set<int> neighbors = adj[node];
    int sz = neighbors.size();
    if(node == 0) sz++;

    int res = ceil(log2(sz));
    for(int ni: neighbors) {
        res += dfs(ni) + 1;
    }

    return res;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        adj[x].insert(y);
        adj[y].insert(x);
    }

    cout << dfs(0) << endl;

    return 0;
}