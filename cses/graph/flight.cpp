#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, m;
vi dist;
vector<bool> visited;
vi child;
vector<set<int>> adj;

int dfs(int node) {
    if(visited[node]) return dist[node];
    visited[node] = true;
    if (adj[node].size() == 0) return -1;
    int longest = -1;
    int longestchild = -1;
    for(int c : adj[node]) {
        int currlen = dfs(c);
        if(currlen > longest) {
            longest = currlen;
            longestchild = c;
        }
    }
    if (longest == -1) return longest;
    child[node] = longestchild;
    dist[node] = longest + 1;
    return dist[node];
}

int main() {
    cin >> n >> m;
    dist = vi(n, -1);
    child = vi(n, -1);
    adj = vector<set<int>>(n, set<int>{});
    visited = vector<bool>(n, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].insert(b);
    }
    dist[n - 1] = 0;
    visited[n - 1] = true;
    int ans = dfs(0);
    if(ans == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans + 1 << endl;
        for (int curr = 0; curr != n - 1; curr = child[curr]) cout << curr + 1 << " ";
        cout << n << endl;
    }
    return 0;
}