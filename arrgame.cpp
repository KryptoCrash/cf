#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n + 2);
    a[0] = a[n + 1] = -1;
    for (ll i = 1; i <= n; i++) cin >> a[i];

    ll l, r;
    l = r = 0;
    while (a[l] < a[l + 1]) l++;
    reverse(a.begin(), a.end());
    while (a[r] < a[r + 1]) r++;

    cout << (l % 2 || r % 2 ? "Alice" : "Bob") << endl;

    return 0;
}