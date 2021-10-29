#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;

bool cmp(pi a, pi b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vpi a(n * m);
    map<int, set<int>> mp;
    for(int i = 0; i < n * m; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
        if (mp.find(x) != mp.end()) mp[x].insert(i);
        else mp[x] = {};
    }

    sort(a.begin(), a.end(), cmp);

    vpi coords(n * m);
    int curr = 0;
    for (int i = 0; i < n * m; i++) {
        coords[a[i].second] = {i, a[i].first};
    }

    int ans = 0;
    vector<bool> used(n * m);
    for (int i = 0; i < n * m; i++) {
        int ch = coord[i];
        for (int j = (ch / m) * m; j < ch; j++) {
            ans += used[j];
        }
        used[ch] = true;
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}