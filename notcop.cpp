#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll maxn = 50;

int main() {
    ll n;
    cin >> n;

    ll a[maxn];
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<ll> fact;

    for(ll i = 0; i < n; i++) {
        ll v = a[i];
        for (ll j = 2; j <= 50; j++) {
            if (v % j == 0) {
                fact.insert(j);
                break;
            }
        }
    }

    ll prod = 1;
    for(ll i : fact) {
        prod *= i;
    }

    cout << prod << endl;

    return 0;
}