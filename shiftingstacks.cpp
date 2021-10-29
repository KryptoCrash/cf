#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll maxn = 100 + 8;

bool solve() {
    ll n;
    cin >> n;

    ll h[maxn];
    for (ll i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (ll i = 0; i < n; i++) {
        if(h[i] - i < 0) return false;
        h[i + 1] += h[i] - i;
        h[i] = i;
    }

    return true;
}

int main(int argc, char const *argv[]) {
    ll t;
    cin >> t;

    while(t--) cout << (solve() ? "YES" : "NO") << endl;

    return 0;
}