#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, m;
    cin >> n >> m;
    pi lab;
    vector<vb> grid(n, vb(m));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            if (c == '#') continue;
            grid[i][j] = true;
            if (c == 'L') lab = {i, j};
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}