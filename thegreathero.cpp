#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll maxn = 1e5;

bool solve() {
    ll hero_a, hero_b, n;
    cin >> hero_a >> hero_b >> n;

    ll a[maxn];
    ll b[maxn];
    ll r[maxn];

    ll total = 0;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Calc rounds taken to kill monster i
    for (ll i = 0; i < n; i++) {
        total += (b[i] + hero_a - 1) / hero_a * a[i];
    }

    ll dam = *max_element(a, a + n);

    // Run sim
    return hero_b > (total - dam);
}

int main(int argc, char const *argv[]) {
    ll t;
    cin >> t;

    while(t--) {
        cout << (solve() ? "YES" : "NO") << endl;
    }

    return 0;
}