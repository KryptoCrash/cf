#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vi a(n);
    vi b(n);
    ll tot = 0;
    ll ans = 0;
    ll max_a = 0;
    ll max_b = 0;
    vector<pi> lo;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];

        if ((a[i] + b[i]) - k >= 0) {
            ll ex = (a[i] + b[i]) - k;
            tot += ex;
            ans++;
            if (a[i] - ex >= 0)
                max_a += ex;
            else
                max_a += a[i];

            if (b[i] - ex >= 0)
                max_b += ex;
            else
                max_b += b[i];
        } else {
            tot += a[i] + b[i];
            max_a += a[i];
            max_b += b[i];
        }
    }

    bool works = false;
    for (ll l = tot - max_b; l <= max_a; l++) {
        if (l % k == 0 || (tot - l) % k == 0) {
            if (l != tot - max_b) works = true;
            break;
        }
    }

    ans += max_b / k + (tot - max_b) / k + (ll)works * ((ll)(n % k == 0) + 1);

    // there is a weird case where u can use both a left and right to fix both sides of something
    // this only works because it is possible to create 2 new ones from 1
    // but this is also only works
    // reason being is that once you do this, you are reset to a position that is too far away to do it again
    // this is really only useful when u cant get works

    if(works == false) {
        int a_need = k - ((tot - max_b) % k);
        int b_need = k - (max_b % k);

        for(int i )
    }

    cout << ans << endl;

    return 0;
}