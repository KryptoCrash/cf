#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i + 1];

    ll mx, seq, sum;
    mx = seq = sum = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
        sum += seq += a[i];
        cout << mx * i + sum << endl;
    }

    return 0;
}