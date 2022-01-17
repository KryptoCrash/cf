#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using vpi = vector<pair<ll, ll>>;

const ll mod = 998244353;

int main() {
    ll n;
    cin >> n;

    vi x(n + 2);
    vi y(n + 1);
    vi nxt(n + 1);
    vi init(n + 1);

    vector<array<ll, 3>> a(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    sort(a.begin(), a.end());

    for (ll i = 0; i < n; i++) {
        x[i + 1] = a[i][0];
        y[i + 1] = a[i][1];
        init[i + 1] = a[i][2];
    }

    x[n + 1] = x[n];

    for (ll i = n; i > 0; i--) {
        nxt[i] = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
    }

    //for (ll i = 1; i <= n; i++) cout << nxt[i] << " ";
    //cout << endl;

    vi sum(n + 1);
    vi psum(n + 1);

    for (ll i = 1; i <= n; i++) {
        ll sucdist = x[nxt[i]] - y[i];

        sum[i] = psum[i - 1] - psum[nxt[i] - 1] + sucdist + x[i + 1] - x[i];

        sum[i] %= mod;

        //cout << "TH " << sum[i] << " " << endl;

        psum[i] = psum[i - 1] + sum[i];
        psum[i] %= mod;
    }

    ll ans = x[1] + 1;
    for (ll i = 1; i <= n; i++) {
        if (init[i])
            ans += sum[i];
        else
            ans += x[i + 1] - x[i];
        ans %= mod;
        // cout << ans << endl;
    }

    ans %= mod;

    if(ans < 0) ans += mod; 

    cout << ans << endl;

    return 0;
}