#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vpi = vector<pair<ll, ll>>;
using vi = vector<ll>;

bool solve() {
    ll n, m;
    cin >> n >> m;

    vi a(m);
    vi need(n);
    for (ll i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;

        if (i >= 2) need[a[i]]++;
    }

    if (m <= 2) {
        return true;
    }

    vi setup;

    if (a[0] == a[1]) {
        if (a[2] < a[0]) {
            for (ll i = a[0] - 1; i >= 0; i--) setup.push_back(i);
            for (ll i = 0; i <= a[0] - 1; i++) setup.push_back(i);
        } else {
            for (ll i = a[0] + 1; i <= n - 1; i++) setup.push_back(i);
            for (ll i = n - 1; i >= a[0] + 1; i--) setup.push_back(i);
        }
    } else {
        if (a[0] < a[1]) {
            for (ll i = a[0] - 1; i >= 0; i--) setup.push_back(i);
            for (ll i = 0; i <= n - 1; i++) setup.push_back(i);
            for (ll i = n - 1; i >= a[1] + 1; i--) setup.push_back(i);
        } else {
            for (ll i = a[1] - 1; i >= 0; i--) setup.push_back(i);
            for (ll i = 0; i <= n - 1; i++) setup.push_back(i);
            for (ll i = n - 1; i >= a[0] + 1; i--) setup.push_back(i);
        }
    }

    vpi pos(n, {-1, -1});
    vi cnt(n);
    for (ll i = 0; i < setup.size(); i++) {
        if (pos[setup[i]].first == -1)
            pos[setup[i]].first = i;
        else
            pos[setup[i]].second = i;

        cnt[setup[i]]++;
    }

    ll l = 0;
    ll r = setup.size() - 1;

    for (ll j = 2; j < m; j++) {
        ll v = a[j];
        ll p1 = pos[v].first;
        ll p2 = pos[v].second;

        need[v]--;

        bool w1 = p1 != -1 && p1 >= l && p1 <= r;
        bool w2 = p2 != -1 && p2 >= l && p2 <= r;

        if (!w1 && !w2) return false;
        if (w1 && !w2) p2 = p1;
        if (w2 && !w1) p1 = p2;
        stack<ll> rem;
        if (p1 - l < r - p2) {
            for (ll i = l; i <= p1; i++) {
                cnt[setup[i]]--;
                rem.push(setup[i]);
                if (cnt[setup[i]] < need[setup[i]]) {
                    while (!rem.empty()) {
                        cnt[rem.top()]++;
                        rem.pop();
                    }

                    goto cutRight;
                }
            }

            l = p1 + 1;
        } else {
            for (ll i = r; i >= p2; i--) {
                cnt[setup[i]]--;
                rem.push(setup[i]);
                if (cnt[setup[i]] < need[setup[i]]) {
                    while (!rem.empty()) {
                        cnt[rem.top()]++;
                        rem.pop();
                    }

                    goto cutLeft;
                }
            }

            r = p2 - 1;
        }

        continue;

    cutRight:
        while (r >= p2) {
            cnt[setup[r]]--;
            if (cnt[setup[r]] < need[setup[r]]) return false;
            r--;
        }
        continue;

    cutLeft:
        while (l <= p1) {
            cnt[setup[l]]--;
            if (cnt[setup[l]] < need[setup[l]]) return false;
            l++;
        }
        continue;
    }

    return true;
}

int main() {
    cout << (solve() ? "YES" : "NO");

    return 0;
}