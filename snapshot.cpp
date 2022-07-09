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

    ll k;
    cin >> k;

    vi x(n);
    for(ll i = 0; i < n; i++) {
        cin >> x[i];
    }

    vi v(n);

    bool works = true;

    for (ll c = 0; c < k; c++) {
        ll t;
        cin >> t;

        map < ll, ll> l;

        for (ll i = 0; i < n; i++) {
            ll q;
            cin >> q;
            l[q]++;
        }
        for (ll i = 0; i < n; i++) {
            if(v[i] == 0) {
                if (l.find(x[i] - t) != l.end()) {
                    v[i] = -1;
                    l[x[i] - t]--;
                } else if (l.find(x[i] + t) != l.end()) {
                    v[i] = 1;
                    l[x[i] + t]--;
                } else {
                    works = false;
                }
            } else {
                if (v[i] == 1) {
                    if (l.find(x[i] + t) != l.end()) l[x[i] + t]--;
                    else
                        works = false;
                } else if(v[i] == -1) {
                    if (l.find(x[i] - t) != l.end())
                        l[x[i] - t]--;
                    else
                        works = false;
                }
            }
        }

        for (pair<ll, ll> val : l) {
            if (val.second != 0) works = false;
        }
    }

    if (!works) cout << 0 << endl;
    else {
        for (ll i : v) cout << i << " ";
        cout << endl;
    }

    return 0;
}