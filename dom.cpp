#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, m, k;
    cin >> m >> n >> k;

    bool works = false;
    while (true) {
        if(k % 2 == 0) {
            if(m % 2 == 0 && n % 2 == 0) {
                works = true;
                break;
            }
            if(m % 2) {
                if (k < n / 2) break;
                m--;
                k = k - (n / 2);
            }
            if(n % 2) {
                swap(m, n);
                k = (n * m) / 2 - k;
            }
        } else {
            if (n % 2 == 0 && m % 2 == 0) break;
            if(m % 2) {
                if (k < n / 2) break;
                m--;
                k = k - (n / 2);
            }
            if(n % 2) {
                swap(m, n);
                k = (n * m) / 2 - k;
            }
        }
    }

    cout << (works ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}