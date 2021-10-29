#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, k, l;

bool ok(ll r, vi a) {
    vi p(n);
    for (int i = 0; i < n; i++) {
        p[i] = a[i];
    }

    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    int start = 0;
    for (int i = 0; i < r; i++) {
        if (p[i] < r) {
            start = i;
            break;
        } else if (i == r - 1)
            return true;
    }

    ll curr_k = k;

    // simulate for each addition
    while (curr_k > 0) {
        ll diff = min(r - p[start], curr_k);
        for (int i = start; i < min(n, start + l); i++) {
            p[i] += diff;
        }

        for (int i = start; i < r; i++) {
            if (p[i] < r) {
                start = i;
                break;
            } else if (i == r - 1)
                return true;
        }

        curr_k -= diff;
    }

    return false;
}

int main() {
    ifstream fin("acowdemia.in");

    fin >> n >> k >> l;

    vi a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }

    ll lo = 0;
    ll hi = n;

    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (ok(mid, a)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << endl;

    return 0;
}