#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<array<ll, 3>> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i][1];
        a[i][2] = true;
    }

    for(ll i = 0; i < n; i++) {
        cin >> a[i][0];
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    while(true) {
        bool works = false;
        for (ll i = 0; i < n; i++) {
            if(a[i][2] && (k >= a[i][1])) {
                a[i][2] = false;
                k += a[i][0];
                works = true;
                break;
            }
        }
        if (!works) break;
    }
    cout << k << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}