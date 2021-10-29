#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll maxn = 1e5+5;

int main(int argc, char const *argv[]) {
    ll n, k;
    cin >> n >> k;

    ll a[maxn];
    ll t[maxn];

    ll tot = 0;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> t[i];
        tot += a[i] * t[i];
    }

    ll pot = 0;
    ll maxpot = 0;

    for (int i = 0; i < k; i++) {
        pot += a[i] * (t[i] ^ 1);
    }

    maxpot = max(pot, maxpot);

    for (ll i = 0; i < n - k + 1; i++) {
        pot -= a[i] * (t[i] ^ 1);
        pot += a[i + k] * (t[i + k] ^ 1);
        
        maxpot = max(pot, maxpot);
    }

    cout << tot + maxpot << endl;

    return 0;
}