#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

void bin(ll n) {
    ll i;
    cout << "0";
    for (i = 1 << 30; i > 0; i = i / 2) {
        if ((n & i) != 0) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << endl;
}

void solve() {
    ll a, b;
    cin >> a >> b;

    ll ans = 0;

    queue<pi> q;
    q.push({a, 0});
    set<ll> vis;
    vis.insert(a);
    map<ll, ll> prev;
    while (!q.empty()) {
        ll v = q.front().first;
        ll d = q.front().second;

        q.pop();
        if(v == b) {
            ans = d;

            break;
            
        }

        // add 1
        if(vis.find(v + 1) == vis.end()) {
            vis.insert(v + 1);
            q.push({v + 1, d + 1});
            prev[v + 1] = v;
            if(b == v + 1) {
                ans = d + 1;
                break;
            }
        }
        if(vis.find(v * 2) == vis.end() && v < b * 2) {
            vis.insert(v * 2);
            q.push({v * 2, d + 1});
            prev[v * 2] = v;
            if (b == v * 2) {
                ans = d + 1;
                break;
            }
        }
        if((v % 2 == 0 ) && (vis.find(v >> 1) == vis.end())) {
            vis.insert(v >> 1);
            prev[v >> 1] = v;
            q.push({v >> 1, d + 1});
            if (b == v >> 1) {
                ans = d + 1;
                break;
            }
        }
    }

    

    ll cur = b;
    vi path;
    path.push_back(b);
    while (prev.find(cur) != prev.end()) {
        cout << cur << endl;
        cur = prev[cur];
        path.push_back(cur);
    }

    reverse(path.begin(), path.end());
    

    cout << "ANS " << ans << endl;

    

    cout << endl;

    for(ll i : path) {
        bin(i);
    }
    cout << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    while (n--) solve();

    return 0;
}