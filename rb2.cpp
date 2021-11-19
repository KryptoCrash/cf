#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    map<char, pi> dir({
        {'L', {-1, 0}},
        {'R', {1, 0}},
        {'U', {0, -1}},
        {'D', {0, 1}},
    });

    vector<vi> d(n, vi(m));
    vector<vector<bool>> vis(n, vector<bool>(m));

    function<pi(int, int)> dfs = [&](int x, int y) {
        if(x < 0 || y < 0 || x >= n || y >= m) return make_pair(-1, -1);

        if(vis[x][y]) {
            return make_pair(x, y);
        }


    };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}