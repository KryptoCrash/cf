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

    ll n;
    cin >> n;

    vector<vi> a(n, vi(n));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    
    
    function<void(ll, ll)> ff = [&](ll x, ll y) {
        if (x < 0 || x >= n || y < 0 || y >= n) return;
        if (visited[x][y]) return;
    
        visited[x][y] = true;
    
        ff(x + 1, y);
        ff(x - 1, y);
        ff(x, y + 1);
        ff(x, y - 1);
    }



    return 0;
}