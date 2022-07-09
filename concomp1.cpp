#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<set<ll>> ed(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ed[a].insert(b);
        ed[b].insert(a);
    }

    vb vis(n);

    function<void(int)> dfs = [&](int i) {
        if (vis[i]) return;
        vis[i] = true;
        for (int ch : ed[i]) dfs(ch);
    };

    vi path;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            path.push_back(i);
        }
    }

    cout << path.size() - 1 << endl;

    for (int i = 1; i < path.size(); i++) {
        cout << path[i - 1] + 1 << " " << path[i] + 1 << endl;
    }

    return 0;
}