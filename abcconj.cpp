#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll ans = 0;
    for (ll i = 1; i*i*i<=n; i++) {
        for(ll j = i; j*j*i <= n; j++) {
            if (n / (i * j) - j + 1 < 0) continue;
            ans += n / (i * j) - j + 1;
        }
    }

    cout << ans << endl;

    return 0;
}