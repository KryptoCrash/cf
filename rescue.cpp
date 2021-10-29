#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;

const ll maxn = 3e5 + 8;
const ll mod = 998244353;

ll fact[maxn + 10]{0};
ll invfact[maxn + 10]{0};

ll binpow(ll x, ll n) {
    assert(n >= 0);
    x %= mod;  //note: m*m must be less than 2^63 to avoid ll overflow
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1)  //if n is odd
            res = res * x % mod;
        x = x * x % mod;
        n /= 2;  //divide by two
    }
    return res;
}

ll modinv(ll x) {
    return binpow(x, mod - 2);
}

void precompute() {
    fact[0] = 1;
    invfact[0] = 1;

    for (ll i = 1; i < maxn; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = modinv(fact[i]);
    }
}

ll choose(ll n, ll k) {
    if (n < k) return 0;
    return (fact[n] * ((invfact[k] * invfact[n - k] % mod))) % mod;
}

struct cmp {
    bool operator()(pi a, pi b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
int main(int argc, char const *argv[]) {
    ll n, k;
    cin >> n >> k;

    precompute();

    priority_queue<pi, vector<pi>, cmp> ev;
    ll l[maxn];
    ll r[maxn];

    for (ll i = 0; i < n; i++) {
        cin >> l[i] >> r[i];

        ev.push({l[i], 1});
        ev.push({r[i], -1});
    }

    map<ll, ll> ac;
    map<ll, ll> st;

    ll a = 0;
    while (!ev.empty()) {
        pi curr = ev.top();
        ev.pop();

        a += curr.second;

        // if start, keep track of active set
        if (curr.second == 1) {
            ac[curr.first] = a;
            st[curr.first] = st.find(curr.first) != st.end() ? st[curr.first] + 1 : 1;
        }
    }

    for (ll i = 0; i < n; i++) {
        ev.push({l[i], 1});
        ev.push({r[i], -1});
    }

    ll ans = 0;
    while (!ev.empty()) {
        pi curr = ev.top();
        ev.pop();
        if (curr.second == -1) continue;
        if (ac[curr.first] < k) continue;

        ans += choose(ac[curr.first] - 1, k - 1);
        ans %= mod;
        ac[curr.first]--;
    }

    cout << ans << endl;
    return 0;
}