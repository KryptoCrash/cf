#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    string best = s;
    string bestl = s;

    for (int i = 0; i < s.length(); i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        if (s < best) best = s;
        if (s > bestl) bestl = s;
    }

    cout << best << endl;
    cout << bestl << endl;

    return 0;
}