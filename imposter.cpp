#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<set<pair<int, bool>>> ed(n, set<pair<int, bool>>());

    for (int i = 0; i < m; i++) {
        int a, b;
        string c;

        cin >> a >> b >> c;
        a--, b--;
        ed[a].insert({b, c == "imposter"});
        ed[b].insert({a, c == "imposter"});

        //0=truth 1=lie
    }

    int ans = 0;
    int n_imp = 0;
    int n_crew = 0;
    bool works = true;

    vi vis(n, -1);

    function<void(int, int)> dfs = [&](int v, int c) {
        if(vis[v] != -1) {
            if (vis[v] == (c ^ 1)) works = false;
            return;
        }

        vis[v] = c;
        if (c) n_imp++;
        else
            n_crew++;
        for (pi child : ed[v]) {
            dfs(child.first, c ^ child.second);
        }
    };

    for (int i = 0; i < n; i++) {
        if (vis[i] != -1) continue;
        
        dfs(i, 0);
        if(!works) {
            cout << -1 << endl;
            return;
        }

        ans += max(n_crew, n_imp);

        n_crew = 0;
        n_imp = 0;
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