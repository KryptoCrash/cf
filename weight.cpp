#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vpi = vector<pair<ll, ll>>;

void solve() {
    int e, w;
    cin >> e >> w;

    vector<vi> x(e, vi(w));
    vector<vi> cnt(e, vi(101));

    ll randm = 0;

    for (int i = 0; i < e; i++) {
        for (int j = 0; j < w; j++) {
            ll v;
            cin >> v;
            cnt[i][j]+=v;
            if (i == e - 1) randm += v;
        }
    }

    vector<vpi> st;
    ll ans = 0;

    for (int i = 0; i < e; i++) {
        cout << ans << endl;
        bool works = true;
        bool done = false;
        ll thing = -1;
        for (int k = 0; k < st.size(); k++) {
            bool curbad = works;
            if (!curbad && !done) {
                thing = k;
                done = true;
            }

            for (int g = 0; g < st[k].size(); g++) {
                ll v = st[k][g].first;
                ll cn = st[k][g].second;

                ll excess = max(0LL, cn - cnt[i][v]);
                if (!works) excess = cnt[i][v];
                cnt[i][v] -= excess;
                ans += excess;

                if (excess > 0) works = false;
            }
        }

        if (thing != -1) {
            for (int j = st.size() - 1; j >= 0; j--) {
                st.pop_back();
                if (j == thing) break;
            }
        }

        vpi lol(101);
        for (int v = 0; v <= 100; v++) {
            lol[v] = {v, cnt[i][v]};
            ans+=cnt[i][v];
        }

        st.push_back(lol);
    }

    cout << ans << endl;

    cout << ans + randm << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}