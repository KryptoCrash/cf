#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, m, r;

bool milkcmp(pi a, pi b) {return a.second > b.second;}
bool cmp(ll a, ll b) { return a > b; }

int main() {
    ifstream fin("rental.in");
    ofstream fout("rental.out");

    fin >> n >> m >> r;

    vi w(n);
    for(ll i = 0; i < n; i++) {
        fin >> w[i];
    }

    sort(w.begin(), w.end(), cmp);

    vector<pi> milk(m);
    for (ll i = 0; i < m; i++) {
        fin >> milk[i].first >> milk[i].second;
    }

    sort(milk.begin(), milk.end(), milkcmp);

    vi rent(r);
    for(ll i = 0; i < r; i++) {
        fin >> rent[i];
    }

    sort(rent.begin(), rent.end(), cmp);

    // prefix sums
    vi psum_milk(n + 1);

    ll currentFarm = 0;
    for (ll i = 0; i < n; i++) {
        ll use = 0;
        while(!(currentFarm >= m || w[i] <= 0)) {
            ll curr = min(milk[currentFarm].first, w[i]);
            w[i] -= curr;
            milk[currentFarm].first -= curr;
            use += curr * milk[currentFarm].second;
            if (milk[currentFarm].first == 0) currentFarm++;
        }
        psum_milk[i + 1] = psum_milk[i] + use;
    }

    // prefix sums rent
    vi psum_rent(n + 1);
    
    for(ll i = 0; i < n; i++) {
        ll use = i < r ? rent[i] : 0;
        psum_rent[i + 1] = psum_rent[i] + use;
    }

    ll best = 0;
    for (ll i = 0; i <= n; i++) {
        best = max(best, psum_milk[i] + psum_rent[n - i]);
    }

    fout << best << endl;

    return 0;
}