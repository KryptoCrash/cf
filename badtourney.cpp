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

    ll n, q;
    cin >> n >> q;

    vector<vpi> setup(2 * n + 1, vpi(n, {0, 0}));

    for (ll i = 0; i < n; i++) {
        cin >> setup[0][i].first >> setup[0][i].second;
    }

    function<void(ll)> sim = [&](ll t) {
        setup[t] = setup[t - 1];
        ll kcw, kcl;
        for (ll i = 0; i < n; i++) {
            if (setup[t][i].first > setup[t][i].second) swap(setup[t][i].first, setup[t][i].second);
            if (i != 0) {
                setup[t][i - 1].first = setup[t][i].first;
            } else {
                kcw = setup[t][i].first;
                kcl = setup[t][i].second;
            }
        }

        setup[t][n - 1].first = kcl;
        setup[t][0].second = kcw;
        for (ll i = 0; i < n; i++) {
            if (setup[t][i].first > setup[t][i].second) swap(setup[t][i].first, setup[t][i].second);
        }
    };

    for (ll i = 1; i <= 2 * n; i++) {
        sim(i);
    }

    swap(setup[2 * n][0].first, setup[2 * n][0].second);

    function<void(ll, ll)> output = [&](ll t, ll shift) {
        vpi x = setup[t];
        if (shift != 0) {
            for (ll i = 0; i < n; i++) {
                x[i].first = setup[t][(i + shift) % n].first;
            }
        }

        for (ll i = 0; i < n; i++) {
            if (x[i].first > x[i].second) swap(x[i].first, x[i].second);
            cout << x[i].first << " " << x[i].second << endl;
        }
    };

    for (ll i = 0; i < q; i++) {
        ll x;
        cin >> x;

        if (x < 2 * n) {
            output(x, 0);
        } else {
            x -= 2 * n;
            x %= n;
            output(2 * n, x);
        }

        cout << endl;
    }

    return 0;
}