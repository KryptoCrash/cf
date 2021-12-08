#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    ll n;
    cin >> n;

    vi a(n);

    priority_queue<pi> pq;
    set<ll> s;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(i);
    }

    for (ll i = 0; i < n; i++) {
        if (gcd(a[i], a[(i + 1) % n]) == 1) pq.push({-i, i});
    }

    vi path;

    while (!pq.empty()) {
        if (s.size() <= 1) {
            path.push_back(*s.begin() + 1);
            break;
        }
        pi top = pq.top();
        pq.pop();

        ll v = a[top.second];

        auto it = next(s.find(top.second));
        if (it == s.end()) it = s.begin();
        if (!pq.empty()) {
            pi nxt = pq.top();
            if (nxt.second == *it) pq.pop();
        }
        auto it2 = it;
        it = next(it);
        if (it == s.end()) it = s.begin();
        if (gcd(v, a[*it]) == 1) pq.push({top.first - n, top.second});
        path.push_back(*it2 + 1);
        s.erase(it2);
    }

    cout << path.size() << " ";

    for (ll i : path) {
        cout << i << " ";
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}