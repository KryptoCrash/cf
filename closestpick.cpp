#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

double solve() {
    ll n, k;
    cin >> n >> k;

    vi a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // find ranges ( deal with first and last one seperately )
    vi ranges(n - 1);
    ll last = a[0];
    for (ll i = 1; i < n; i++) {
        ranges[i - 1] = a[i] - last;
        last = a[i];
    }

    sort(ranges.begin(), ranges.end());
    reverse(ranges.begin(), ranges.end());

    // find actual length of ranges
    vi actual;
    for(ll i : ranges) {
        actual.push_back(i / 2);
    }

    // dealing with the first last one
    actual.push_back(k - a.back());
    actual.push_back(a[0] - 1);

    // get the top two ranges and use them
    sort(actual.begin(), actual.end());
    reverse(actual.begin(), actual.end());

    ll possible = 0;

    if(actual.size() > 0) possible += actual[0];
    if (actual.size() > 1) possible += actual[1];

    if(ranges.size() > 0) possible = max(possible, ranges[0] - 1);

    return (double)possible / (double)k;
}

int main() {
    ll t;
    cin >> t;

    for (ll i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }

    return 0;
}