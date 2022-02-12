#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

void solve() {
    ll a, b;
    cin >> a >> b;

    ll mn = 1e9;

    for (ll i = 0; i < 30; i++) {
        // switch
        for (ll j = 0; j < 30; j++) {
            ll v = a * (1 << j);

            ll dif = b - v;
            if (dif < 0) continue;
            ll cnt = 0;

            for (ll k = j; k >= 0; k--) {
                for (ll w = 0;; w++) {
                    ll rem = (1 << k);
                    if (rem <= dif) {
                        cnt += 1;
                        dif -= rem;
                        continue;
                    }
                    break;
                }
            }

            if (dif == 0) mn = min(mn, i + j + cnt);
        }

        if (a % 2 == 0)
            a >>= 1;
        else
            a++;
        
    }

    cout << mn << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    while (n--) solve();

    return 0;
}