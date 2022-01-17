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

    ll n;
    cin >> n;

    ll last = 0;

    ll sum = 0;

    function<ll(ll)> q = [&](ll c) {
        cout << "+ " << c << endl;
        sum += c;
        ll res;
        cin >> res;
        return res;
    };

    ll lo = 0;
    ll ans = 0;
    for (ll bit = 9; bit >= 0; bit--) {
        if ((1 << bit) >= n) continue;
        ll val = (1 << bit) + lo;
        if (val >= n) val -= n, last--;
        
        ll res = q(val);
        lo = 0;
        if (res > last) {
            lo = n - (1 << bit);
            last++;
        } else {
            ans += (1 << bit);
        }
    }

    cout << "! " << n - (ans + 1) + sum << endl;

    return 0;
}