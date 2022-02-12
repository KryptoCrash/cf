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

    /*
    for (ll a = 0; a < 2; a++) {
        for (ll b = 0; b < 2; b++) {
            for (ll c = 0; c < 2; c++) {
                for (ll d = 0; d < 2; d++) {
                    if(((a | b) ^ (c | d) ^ ((a ^ c) | (b ^ d))) == 0) {
                        cout << a << " " << b << " " << c << " " << d << endl;
                    }
                }
            }
        }
    }

    0 0 0 0
    0 0 0 1
    0 0 1 0
    0 0 1 1
    0 1 0 0
    0 1 0 1
    1 0 0 0
    1 0 1 0
    1 1 0 0
    1 1 1 1

    */

    ll n;
    cin >> n;

    vpi p(n);
    for (ll i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        vi cnt(4);
        for (ll j = i + 1; j < n; j++) {
            ll bit = ((abs(p[j].first - p[i].first) / 2) % 2) * 2 + (((abs(p[j].second - p[i].second) / 2) % 2));
            ans += cnt[0];
            if (bit == 0)
                ans += cnt[1] + cnt[2] + cnt[3];
            else
                ans += cnt[bit];
            cnt[bit]++;
        }
    }

    cout << ans << endl;

    return 0;
}