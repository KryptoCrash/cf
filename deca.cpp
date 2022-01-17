#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll INF = 1e9+8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin >> k >> m >> n;

    vpi patch(k);

    for (ll i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b;
        patch[i] = {a, b};
    }

    vi bad(m);
    for (ll i = 0; i < m; i++) {
        cin >> bad[i];
    }

    vpi ans(m + 1);

    ll j = 0;
    for (ll i = 0; i < m; i++) {
        vector<ll> p;
        while(j < k && patch[j].first < bad[i]) {
            p.push_back(j);
            j++;
        }

        ll sum = 0;
        for (ll v : p) sum += patch[v].second;

        ans[i].second = sum;

        if(i == 0) {
            ans[i].first = sum;

            continue;
        }

        priority_queue<array<ll, 3>> ev;

        ll l = bad[i - 1];
        ll r = bad[i];
        for (ll v : p) {
            ll pos = patch[v].first;
            ll taste = patch[v].second;

            ll startpos = pos - (r - pos) + 1;
            ll endpos = pos + (pos - l) - 1;

            ev.push({-startpos, 1, taste});
            ev.push({-endpos, -1, taste});


        }

        ll best = 0;
        ll cursum = 0;
        while (!ev.empty()) {
            array<ll, 3> top = ev.top();
            ev.pop();

            cursum += top[1] * top[2];

            best = max(best, cursum);
        }

        ans[i].first = best;
    }

    while (j < k) {
        ans[m].first += patch[j].second;
        ans[m].second += patch[j++].second;
    }

    vector<vi> dp(m + 2, vi(n + 1));
    for (ll i = 0; i <= m; i++) {
        for (ll h = 0; h <= n; h++) {
            if (h > 1) dp[i + 1][h - 2] = max(dp[i + 1][h - 2], dp[i][h] + ans[i].second);
            if (h > 0) dp[i + 1][h - 1] = max(dp[i + 1][h - 1], dp[i][h] + ans[i].first);


        }
    }

    ll ansb = 0;
    for (ll i = 0; i <= m + 1; i++) {
        for (ll h = 0; h <= n; h++) {
            ansb = max(ansb, dp[i][h]);
        }
    }

    cout << ansb << endl;

    return 0;
}