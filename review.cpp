#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, m;
    cin >> m >> n;

    vector<set<pi>> ed(n);

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;

        ed[a].insert({b, c});
        ed[b].insert({a, c});
    }

    vb vis(n);
    vi col(n, -1);
    stack<ll> st;

    bool works = true;
    bool fail = false;

    function<void(int)> dfs = [&](int v) {
        if (vis[v]) return;
        vis[v] = true;

        for (pi ch : ed[v]) {
            if (ch.second != col[v]) {
                if (col[ch.first] == -1) {
                    st.push(ch.first);
                    col[ch.first] = col[v] ^ 1;
                    dfs(ch.first);
                }
                if (col[ch.first] != (col[v] ^ 1)) {
                    works = false;
                    return;
                }
            }
        }
    };

    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            st.push(i);
            col[i] = 0;
            dfs(i);
            if (works)
                continue;
            else {
                works = true;
                while (st.size() > 0) {
                    ll th = st.top();
                    st.pop();
                    col[th] = -1;
                    vis[th] = false;
                }
                col[i] = 1;
                dfs(i);
                if (!works) {
                    fail = true;
                    break;
                }

            }
        }
    }

    cout << (!fail ? "We can do it!" : "Better luck next time.") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}