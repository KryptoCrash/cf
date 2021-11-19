#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

void solve() {
    ll n;
    cin >> n;

    vi a(n);
    vi b(n);

    vi a_sz(n);
    vi b_sz(n);

    ll tot = n * (n - 1) * (n - 2) / 6;

    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        a_sz[a[i]]++, b_sz[b[i]]++;
    }

    ll comp = 0;
    for (ll i = 0; i < n; i++) {
        comp += (a_sz[a[i]] - 1) * (b_sz[b[i]] - 1);
    }

    cout << tot - comp << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}