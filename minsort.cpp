#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int n;

int minq(int i, int j) {
    i++, j++;
    int ans;
    cout << "M " << i << " " << j << endl;
    cin >> ans;
    return ans - 1;
}

void swapq(int i, int j) {
    i++, j++;
    if (i == j) return;
    int ans;
    cout << "S " << i << " " << j << endl;
    cin >> ans;
    assert(ans == 1);
    return;
}

void done() {
    int ans;
    cout << "D" << endl;
    cin >> ans;
    assert(ans == 1);
    return;
}

void solve() {
    // for a solve get the min and put it to the front
    for (int i = 0; i < n - 1; i++) {
        int curr_min = minq(i, n - 1);
        swapq(i, curr_min);
    }

    done();
}

int main() {
    int t;
    cin >> t >> n;

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}