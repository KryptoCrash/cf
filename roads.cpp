#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, m;
vector<set<int>> adj;
vector<bool> visited;

void dfs(int node) {
    if (visited[node]) return;

    visited[node] = true;

    for(int child : adj[node]) {
        dfs(child);
    }
}

int main() {
    cin >> n >> m;

    adj = vector<set<int>>(n, set<int>{});
    visited = vector<bool>(n, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    // dfs for connected components
    vector<int> repr;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            sum++;
            repr.emplace_back(i + 1);
            dfs(i);
        }
    }

    cout << sum - 1 << endl;

    for(int i = 1; i < repr.size(); i++) {
        cout << repr[i] << ' ' << repr[i - 1] << endl;
    }

    return 0;
}