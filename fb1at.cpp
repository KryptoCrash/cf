#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<char> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    char c = '\0';
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'F') continue;
        if(a[i] == 'O') {
            if (c == 'X') ans++;
            c = 'O';
        }
        if (a[i] == 'X') {
            if (c == 'O') ans++;
            c = 'X';
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}