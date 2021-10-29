#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

bool ok(ll r, vi a, ll n, ll k, ll l) {
    if (r == 0) return true;

    vi p(n);
    for (ll i = 0; i < n; i++) {
        p[i] = a[i];
    }

    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    
    ll start = 0;
    
    for (ll i = 0; i < min(r, n); i++) {
        if (p[i] < r) {
            start = i;
            break;
        } else if(i == r - 1)
            return true;
    }
    

    ll curr_k = k;

    vi change(n + 1);
    ll curr_sum = 0;

    // simulate for each addition
    while (curr_k > 0) {
        ll diff = min(r - (p[start] + curr_sum + change[start]), curr_k);
        change[start] += diff;
        change[min(start + l, n)] -= diff;

        for (ll i = start; i < min(r, n); i++) {
            curr_sum += change[i];
            if ((curr_sum + p[i]) < r) {
                start = i;
                curr_sum -= change[i];
                break;
            } else if (i == r - 1)
                return true;
        }

        curr_k -= diff;
    }

    return false;
}

int main() {
    ll n, k, l;
    cin >> n >> k >> l;

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll lo = 0;
    ll hi = n; 

    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (ok(mid, a, n, k, l)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << endl;

    return 0;
}