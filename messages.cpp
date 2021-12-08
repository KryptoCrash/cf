#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll N = 2e5 + 8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi m(n);
    vi k(n);
    for (ll i = 0; i < n; i++) {
        cin >> m[i] >> k[i];
    }

    ll bestt = 1;
    ll bestans = 0;
    vi bestpath;

    for (ll t = 1; t <= 20; t++) {
        vpi coeff(N);
        for (ll i = 0; i < N; i++) {
            coeff[i] = {0, i};
        }
        for (ll i = 0; i < n; i++) {
            coeff[m[i]].first += min(t, k[i]);
        }

        sort(coeff.rbegin(), coeff.rend());

        ll cans = 0;
        vi path;
        for (ll i = 0; i < t; i++) {
            cans += coeff[i].first;
            path.push_back(coeff[i].second);
        }

        if (cans * bestt > bestans * t) {
            bestans = cans;
            bestt = t;
            bestpath = path;
        }
    }

    cout << bestt << endl;

    for (ll i = 0; i < bestt; i++) {
        cout << bestpath[i] << " ";
    }

    cout << endl;

    return 0;
}