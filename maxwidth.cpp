#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, m;

int main() {
    cin >> n >> m;

    vector<char> _long(n);
    for(int i = 0; i < n; i++) {
        cin >> _long[i];
    }

    vector<char> _short(m);
    for(int i = 0; i < m; i++) {
        cin >> _short[i];
    }

    vector<int> first(m);
    vector<int> last(m);

    int lp = 0;
    for (int i = 0; i < m; i++) {
        while(_short[i] != _long[lp]) {
            lp++;
        }

        first[i] = lp;
        lp++;
    }

    int rp = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (_short[i] != _long[rp]) {
            rp--;
        }

        last[i] = rp;
        rp--;
    }

    int best = 0;
    for (int i = 1; i < m; i++) {
        best = max(best, last[i] - first[i - 1]);
    }

    cout << best << endl;

    return 0;
}