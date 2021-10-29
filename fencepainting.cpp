#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a;
    vector<int> b;
    vector<int> c;

    int in;
    for (int i = 0; i < n; i++) {
        cin >> in;
        a.emplace_back(in);
    }
    for (int i = 0; i < n; i++) {
        cin >> in;
        b.emplace_back(in);
    }
    for (int i = 0; i < m; i++) {
        cin >> in;
        c.emplace_back(in);
    }

    multimap<int, int> inc;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) inc.emplace(b[i], i);
    }

    auto last_v = inc.find(c.back());
    auto last_resort = find(b.begin(), b.end(), c.back());
    int last_i;
    if (last_v == inc.end()) {
        if (last_resort == b.end()) {
            cout << "NO" << endl;
            return;
        }
        else
            last_i = last_resort - b.begin();
    } else {
        inc.erase(last_v);
        last_i = last_v->second;
    }

    vector<int> ans;
    for (int i = 0; i < m; i++) {
        auto it = inc.find(c[i]);
        if (it != inc.end()) {
            ans.emplace_back(it->second);
            inc.erase(it);
        } else
            ans.emplace_back(last_i);
    }

    for (int i = 0; i < m; i++) {
        a[ans[i]] = c[i];
    }

    for (int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

    for (int i = 0; i < m; i++) {
        cout << ans[i] + 1 << " ";
    }

    cout << endl;

    return;
}

int main() {
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}