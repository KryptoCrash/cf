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

    vi a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    // monotonic stack
    vector<array<ll, 2>> best(n);
    for (ll b = 0; b < 2; b++) {
        stack<pi> st;
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ll cnt = 0;
            while (!st.empty()) {
                pi top = st.top();
                if (top.first > a[i]) {
                    st.pop();
                    ans -= (top.first - a[i]) * top.second;
                    cnt++;
                } else
                    break;
            }
            st.push({a[i], cnt + 1});
            ans += a[i];

            best[i][b] = ans;
        }
        reverse(a.begin(), a.end());
    }

    ll mx = 0;
    ll mx_i = 0;
    for (ll i = 0; i < n; i++) {
        if(best[i][0] + best[n-i-1][1] - a[i] > mx) {
            mx = best[i][0] + best[n - i - 1][1] - a[i];
            mx_i = i;
        }
    }

    stack<pi> s1, s2;

    // monotonic stack
    for (ll b = 0; b < 2; b++) {
        stack<pi> st;
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ll cnt = 0;
            while (!st.empty()) {
                pi top = st.top();
                if (top.first > a[i]) {
                    st.pop();
                    ans -= (top.first - a[i]) * top.second;
                    cnt++;
                } else
                    break;
            }
            st.push({a[i], cnt + 1});
            ans += a[i];

            if (i == mx_i && b == 0) s1 = st;
            if (i == n - mx_i - 1 && b == 1) s2 = st;
        }
        reverse(a.begin(), a.end());
    }

    vi path;
    vi path2;

    while(!s1.empty()) {
        pi val = s1.top();
        s1.pop();
        for (ll i = 0; i < val.second; i++) {
            path.push_back(val.first);
        }
    }

    while (!s2.empty()) {
        pi val = s2.top();
        s2.pop();
        for (ll i = 0; i < val.second; i++) {
            path2.push_back(val.first);
        }
    }

    reverse(path.begin(), path.end());

    for(ll i : path) {
        cout << i << " ";
    }
    for (ll i = 1; i < path2.size(); i++) {
        cout << path2[i] << " ";
    }

    cout << endl;

    return 0;
}