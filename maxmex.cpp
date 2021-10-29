#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

void solve() {
    int n;
    cin >> n;

    vector<char> ai(n);
    vector<char> bi(n);
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> ai[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> bi[i];
    }
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        char x = ai[i];
        char y = bi[i];

        if (x == y && x == '0') {
            a[i] = 0;
            zeros++;
        }
        if (x == y && x == '1') a[i] = 1;
        if (x != y) a[i] = 2;
    }
    int ans = 0;
    bool sol = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == 2) ans += 2;
        if (i != 0 && !sol && ((a[i] == 1 && a[i - 1] == 0) || (a[i] == 0 && a[i - 1] == 1))) {
            ans += 2;
            sol = true;
            zeros--;
        } else
            sol = false;
    }
    ans += zeros;

    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}