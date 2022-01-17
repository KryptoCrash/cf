#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n;
    cin >> n;

    vector<vector<ll>> a(n + 1, vector<ll>(n + 1, 1));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            char c;
            cin >> c;
            a[i][j] = c == '1';
        }
    }

    bool works = true;
    for (ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(a[i][j]) {
                if (!(a[i + 1][j] || a[i][j + 1])) works = false;
            }
        }
    }

    cout << (works ? "YES" : "NO") << endl;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        ll t;
        cin >> t;
        while (t--) solve();

        return 0;
}