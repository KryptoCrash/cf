#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n;

bool ycmp(pi a, pi b) { return a.second < b.second; }

vi calc_psum_hor(vector<pi> a) {
    // calc for horizontal line
    ll leftmost, rightmost;
    leftmost = rightmost = a[0].second;
    vi psum_hor(n + 1);

    for (ll i = 0; i < n; i++) {
        leftmost = min(leftmost, a[i].second);
        rightmost = max(rightmost, a[i].second);
        ll area = abs(a[i].first - a[0].first) * abs(rightmost - leftmost);
        psum_hor[i + 1] = area;
    }

    return psum_hor;
}

int main() {
    ifstream fin("split.in");
    ofstream fout("split.out");

    fin >> n;

    vector<pi> a(n);
    for (ll i = 0; i < n; i++) {
        fin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    ll one_width = a[n - 1].first - a[0].first;

    sort(a.begin(), a.end(), ycmp);

    ll one_height = a[n - 1].second - a[0].second;

    sort(a.begin(), a.end());

    ll one_area = one_width * one_height;

    vi psum_hor = calc_psum_hor(a);

    reverse(a.begin(), a.end());
    vi ssum_hor = calc_psum_hor(a);

    for (ll i = 0; i < n; i++) {
        pi temp = a[i];
        a[i].first = temp.second;
        a[i].second = temp.first;
    }

    sort(a.begin(), a.end());

    vi psum_ver = calc_psum_hor(a);
    reverse(a.begin(), a.end());
    vi ssum_ver = calc_psum_hor(a);

    ll best = 1e18+4;
    for (ll i = 1; i <= n; i++) {
        best = min(best, psum_hor[i] + ssum_hor[n - i]);
    }

    for (ll i = 1; i <= n; i++) {
        best = min(best, psum_ver[i] + ssum_ver[n - i]);
    }

    fout << one_area - best << endl;

    return 0;
}