#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, m;
    cin >> n >> m;

    vi a(n);
    vi b(m);

    priority_queue<pi> evup;
    priority_queue<pi> evdown;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (ll i = 0; i < n; i++) {
        if(a[i] > 0) evup.push({-a[i], 1});
        else
            evdown.push({a[i], 1});
    }
    for (ll i = 0; i < m; i++) {
        if (b[i] > 0) evup.push({-b[i], 0});
        else
            evdown.push({b[i], 0});
    }

    ll cur = 0;
    ll l, r, last;
    l = r = last = 0;
    ll bestup = 0;
    while (!evup.empty()) {
        pi e = evup.top();
        e.first *= -1;
        evup.pop();
        if (e.second) cur++;
        else {
            if (cur == 0) continue;
            if (last == e.first) bestup++;
            while (b[r] != e.first) {
                r++;
            }

            while(b[r] - b[l] + 1 > cur) {
                l++;
            }
            bestup = max(bestup, r - l + 1);
        }
        last = e.first;
    }

    reverse(b.begin(), b.end());
    for (ll i = 0; i < m; i++) {
        b[i] *= -1;
    }

    cur = 0;
    l = r = last = 0;
    ll bestdown = 0;
    while (!evdown.empty()) {
        pi e = evdown.top();
        e.first *= -1;
        evdown.pop();
        if (e.second)
            cur++;
        else {
            if (cur == 0) continue;
            if (last == e.first) bestdown++;
            while (b[r] != e.first) {
                r++;
            }

            while (b[r] - b[l] + 1 > cur) {
                l++;
            }

            bestdown = max(bestdown, r - l + 1);
        }
        last = e.first;
    }

    cout << bestup + bestdown << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}