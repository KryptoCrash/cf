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

    ll n, mod;
    cin >> n >> mod;

    vi ps(n + 2);
    ps[n] = 1;

    for (ll i = n - 1; i > 0; i--) {
        ps[i] = 2 * ps[i + 1];

        for (int k = 2; k * i <= n; k++) {
            ps[i] += ps[i * k] - ps[min(n + 1, i * k + k)];
            ps[i] = (mod + (ps[i] % mod)) % mod;
        }

        ps[i] = (mod + (ps[i] % mod)) % mod;
    }

    cout << (mod + ((ps[1] - ps[2]) % mod)) % mod << endl;

    return 0;
}