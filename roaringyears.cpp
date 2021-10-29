#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const int maxn = 8;

vector<ll> roaring;

int solve() {
    int n;
    cin >> n;

    auto it = upper_bound(roaring.begin(), roaring.end(), n);
    if (it == roaring.end()) assert(false);
    return *it;
}

int main() {
    // generate all roaring numbers lmao
    for (int start = 1; start < (int)pow(10, maxn); start++) {
        string curr;
        curr += to_string(start);
        for (int cnt = 1; curr.length() < maxn; cnt++) {
            curr += to_string(start + cnt);
            roaring.push_back(stoll(curr));
        }
    }

    sort(roaring.begin(), roaring.end());

    ll t;
    cin >> t;

    for (ll i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }

    return 0;
}