#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi p(n + 1);
    vi c(n + 1);
    ll root;
    for (ll i = 1; i <= n; i++) {
        cin >> p[i] >> c[i];
        if (p[i] == 0) root = i;
    }

    vector<set<ll>> ed(n + 1);

    for (ll i = 1; i <= n; i++) {
        ed[p[i]].insert(i);
    }

    bool works = true;

    function<vector<ll>(ll)> dfs = [&](ll v) {
        vector<ll> cur;
        for (ll ch : ed[v]) {
            vector<ll> chv = dfs(ch);
            cur.insert(cur.begin(), chv.begin(), chv.end());
        }

        if (c[v] > cur.size()) {
            works = false;
            return vi{};
        } else {
            cur.insert(cur.begin() + c[v], v);
            //cout << "CUR: ";
            //for (int i : cur) cout << i << " ";
            //cout << endl;
            //cout << endl;
            return cur;
        }
    };

    vi last = dfs(root);

    if(!works) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;

        vi ans(n);

        for (int i = 0; i < last.size(); i++) {
            //cout << last[i] << endl;
            ans[last[i] - 1] = i + 1;
        }

        for(int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}