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

    ll r, c;
    cin >> r >> c;
    r--, c--;

    vector<vi> grid(n, vi(m));
    for (ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            char cg;
            cin >> cg;
            grid[i][j] = cg == 'B';
        }
    }

    ll ans = 3;
    for (ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if (i == r && j == c && grid[i][j]) ans = min(ans, 0LL);
            else if((i == r || j == c ) && grid[i][j])
                ans = min(ans, 1LL);
            else if(grid[i][j])
                ans = min(ans, 2LL);
        }
    }

    cout << (ans == 3 ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}