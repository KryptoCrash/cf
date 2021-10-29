#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

void solve() {
    ll n;
    cin >> n;
    set<ll> a;
    set<ll> twice;
    for (ll i = 0; i < n; i++) {
        ll c;
        cin >> c;
        if (a.find(c) != a.end()) twice.insert(c);
        a.insert(c);
    }

    set<ll> include;
    for (ll i : a) {
        for (ll j : a) {
            if (i == j && twice.find(i) == twice.end()) continue;
            ll x = abs(i - j);
            if (a.find(x) == a.end()) {
                include.insert(x);
            }
        }
    }

    while (!include.empty() && a.size() <= 300) {
        while(!include.empty()) {
            auto x = include.begin();
            a.insert(*x);
            include.erase(x);
        }
        for (ll i : a) {
            for (ll j : a) {
                if (i == j && twice.find(i) == twice.end()) continue;
                ll x = abs(i - j);
                if (a.find(x) == a.end()) {
                    include.insert(x);
                }
            }
        }
    }

    if(a.size() > 300 || !include.empty()) {
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
        cout << a.size() << endl;
        for (ll i : a) cout << i << " ";
        cout << endl;
    }
    return;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}