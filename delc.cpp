#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

vb prime(1e6 + 8, true);

void solve() {
    ll n, e;
    cin >> n >> e;

    vi a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vb all1(n);
    vb works(n);
    vi sum(n);
    vi sum2(n);

    ll tot = 0;

    for (ll i = 0; i < n; i++) {
        ll last = i - e;

        if(last < 0) {
            if (a[i] == 1) {
                all1[i] = true;
                sum[i] = 1;
            } else if (prime[a[i]]) {
                works[i] = true;
                sum[i] = 1;
            }
        } else {
            if(all1[last]) {
                if(a[i] == 1) {
                    all1[i] = true;
                    sum[i] = sum[last] + 1;
                } else if (prime[a[i]]) {
                    works[i] = true;
                    sum[i] = sum[last] + 1;
                }
            } else if(works[last]) {
                if(a[i] == 1) {
                    works[i] = true;
                    sum[i] = sum[last];
                    sum2[i] = sum2[last] + 1;
                }
            } 
            
        }
        if(!works[i] && !all1[i]) {
            if (a[i] == 1) {
                all1[i] = true;
                sum[i] = 1;
            } else if (prime[a[i]]) {
                works[i] = true;
                sum[i] = max((ll)1, sum2[last] + (ll)1);
                tot += sum[i] - 1;
            }
        } else {
            if(works[i] && last >= 0) tot += sum[last]; 
        }
    }

    cout << tot << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    prime[0] = prime[1] = false;
    for (ll i = 2; i < (1e6+8); i++) {
        if (prime[i] && (long long)i * i < (1e6+8)) {
            for (ll j = i * i; j < (1e6+8); j += i)
                prime[j] = false;
        }
    }


    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}