#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll k;
    cin >> k;

    vi p(n);
    vector<set<int>> ed(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        ed[p[i]].insert(i);
    }

        vector<string> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll lo = 1;
    ll hi = k;
    ll mid = 0;

    function<bool(int)> ok = [&](int v) {
        if(a[v] == "max") {
            bool works = false;
            for(int ch : ed[v]) {
                if (ok(ch)) works = true;
            }
            return works;
        } else if (a[v] == "min") {
            bool works = true;
            for(int ch : ed[v]) {
                if (!ok(ch)) works = false;
            }
            return works;
        } else if(a[v] == 0) {
            
        }

        return false;
    };

    while (lo < hi) {
        mid = (lo + hi + 1) / 2;
        if (ok(0)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

        return 0;
}