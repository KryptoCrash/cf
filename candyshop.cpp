#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    set<int> unused;
    vector<set<int>> child(n);
    vector<int> mark(n);
    int ans = 0;

    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        child[p].insert(i);
    }

    for (int i = 0; i < m; i++) {
        mark[(a * i + b) % n]++;
    }

    function<void(int)> dfs = [&](int v) {
        for (int to : child[v]) {
            dfs(to);
        }
        unused.insert(v);
        while (mark[v] > 0) {
            auto top = unused.end();
            ans += *(--top);
            unused.erase(top);
        }
    };

    dfs(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }

    return 0;
}