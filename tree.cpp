#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<set<int>> ed(n, set<int>());

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        ed[u].insert(v);
        ed[v].insert(u);
    }

    queue<pi> bfs;
    vi out(n);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        out[i] = ed[i].size();
        if (out[i] <= 1) {
            vis[i] = true;
            bfs.push({i, 0});
        }
    }

    int ans = n;

    while (!bfs.empty()) {
        pi v = bfs.front();
        bfs.pop();

        if (v.second == k) break;

        ans--;

        for (int child : ed[v.first]) {
            if (!vis[child]) {
                out[child]--;
                if (out[child] <= 1) {
                    vis[child] = true;
                    bfs.push({child, v.second + 1});
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}