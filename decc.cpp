#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vi cnta(m + 1);
    vi cntb(m + 1);

    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        cnta[a]++;
        cntb[b]++;
    }

    vi cnt2a(2 * m + 1);
    vi cnt2b(2 * m + 1);

    for (ll i = 0; i < m + 1; i++) {
        for (ll j = 0; j < m + 1; j++) {
            cnt2a[i + j] += cnta[i] * cnta[j];
            cnt2b[i + j] += cntb[i] * cntb[j];
        }
    }

    ll sum = 0;
    for (ll i = 0; i < 2 * m + 1; i++) {
        sum += cnt2a[i];
        cout << sum << endl;
        sum -= cnt2b[i];
    }

    return 0;
}