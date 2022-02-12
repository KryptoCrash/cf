#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi nxt_l(n, -1);
    vi nxt_r(n, -1);

    for (ll j = 0; j < 2; j++) {
        stack<pi> s;
        for (ll i = 0; i < n; i++) {
            bool done = false;
            while (!s.empty()) {
                ll top = s.top().first;
                if (top < a[i]) {
                    s.pop();
                    continue;
                }
                if (j == 0)
                    nxt_l[i] = s.top().second;
                else
                    nxt_r[n - i - 1] = n - s.top().second - 1;
                s.push({a[i], i});
                done = true;
                break;
            }
            if (!done) {
                s.push({a[i], i});
            }
        }
        while (!s.empty()) s.pop();
        reverse(a.begin(), a.end());
    }

    ll ans = 0;
    vi sum1(n);
    vi cnt1(n);
    vi sum2(n);
    vi cnt2(n);

    for (ll i = 0; i < n; i++) {
        if (nxt_l[i] != -1) {
            sum1[nxt_l[i]] += i;
            cnt1[nxt_l[i]] += 1;
        }
        if (nxt_r[i] != -1) {
            sum2[nxt_r[i]] += i;
            cnt2[nxt_r[i]] += 1;
        }
    }

    for (ll i = 0; i < n; i++) {
        if (cnt1[i] != 0) ans += sum1[i] - (cnt1[i] * i) + cnt1[i];
    }
    for (ll i = 0; i < n; i++) {
        if (cnt2[i] != 0) ans += (cnt2[i] * i) - sum2[i] + cnt2[i];
    }

    cout << ans << endl;

    return 0;
}