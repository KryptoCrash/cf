#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll maxn = 0x10000 + 8;

int main(int argc, char const *argv[]) {
    ll n, k;

    cin >> n >> k;

    set<ll> chunks;

    for (ll i = 0; i < n; i++) {
        ll y;
        cin >> y;
        chunks.insert(y / 12 + 1);
    }

    vector<ll> dist;

    ll last_chunk = 0;
    for (ll c : chunks) {
        dist.push_back(c - last_chunk);
        last_chunk = c;
    }

    ll min_dist = 0;

    sort(dist.begin(), dist.end(), greater<ll>());

    for (ll i = 0; i < dist.size(); i++) {
        if (i < (k - 1))
            min_dist += 12;
        else if(dist[i] > 0)
            min_dist += (dist[i] - 1) * 12 + 12;
    }

    cout << min_dist << endl;

    return 0;
}