#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll INF = 1e9;

long long gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);
    ll d = b - a;
    ll best = lcm(a, b);
    ll bestk = 0;

    for (ll i = 1; i * i <= d; i++) {
        if (d % i != 0) continue;
        for (ll j = 0; j < 2; j++) {
            ll k = i - (a % i);
            ll l = lcm(a + k, b + k);
            if (l < best) best = l, bestk = k;
            if (l == best && k < bestk) bestk = k;
            if (i * i == d) break;
            i = d / i;
        }
    }

    cout << bestk << endl;

    return 0;
}