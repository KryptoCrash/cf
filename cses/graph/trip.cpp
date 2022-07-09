/*
https://cses.fi/problemset/task/1669
 
dfs and then if a visited node is found again (dont go back to previous node)
and then a cycle is found
if it isnt a cycle, it ends in a leaf
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, m;
vector<set<int>> adj;
vi path;
vector<bool> visited;
vector<bool> evervisited;

void dfs(int node) {
    if (visited[node]) {
        // cycle found
        bool incycle = false;
        vi actualpath;
        for (int i : path) {
            if (i == node) incycle = true;
            if (incycle) actualpath.push_back(i);
        }
        assert(incycle);
        if (incycle) {
            actualpath.push_back(node);
            cout << actualpath.size() << endl;
            for (int c : actualpath) cout << c + 1 << " ";
            cout << endl;
            exit(0);
        }
    }

    visited[node] = true;
    evervisited[node] = true;
    path.push_back(node);

    for (int child : adj[node]) {
        dfs(child);
    }

    path.pop_back();
    visited[node] = false;
}

int main() {
    cin >> n >> m;

    adj = vector<set<int>>(n);
    visited = vector<bool>(n, false);
    evervisited = vector<bool>(n, false);
    path = vi();

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].insert(b);
    }

    for (int i = 0; i < n; i++) {
        if (!evervisited[i]) dfs(i);
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}