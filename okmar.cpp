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

    vector<vb> a(n, vb(m, 0));
    vi psum(m + 1);

    for (ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c == 'X';
            if (i > 0 && j > 0 && a[i][j - 1] && a[i - 1][j]) psum[j + 1]++;
        }
    }
    
    for(int i = 0; i < m; i++) {
        psum[i + 1] += psum[i];
    }

    ll q;
    cin >> q;

    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;

        cout << (psum[r] - psum[l] == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}