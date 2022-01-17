#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n;
    cin >> n;

    vpi a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    ll goal = 0;
    ll goalpt = 0;
    ll last = 0;
    ll lasttime = 0;

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        // figure out where we are
        ll curtime = a[i].first;
        ll cur = last + goal * (curtime - lasttime);

        //cout << "TIME " << curtime << " " << cur << endl;

        // figure out if we reached goal
        bool reached = false;
        if (goal == -1) {
            if(cur <= goalpt) {
                reached = true;
            }
        } else if(goal == 1) {
            if (cur >= goalpt) reached = true;
        } else if (goal == 0)
            reached = true;

        if (reached) cur = goalpt;
        //cout << "REACHED " << reached << endl;

        if(i > 0) {
            ll lastgoal = a[i - 1].second;
            if (lastgoal <= max(cur, last) && lastgoal >= min(cur, last)) {
                ans++;
                //cout << i - 1 << endl;
            }
        }

        last = cur;
        if (reached) {
            goal = (a[i].second - last) / abs(a[i].second - last);
            goalpt = a[i].second;
            if (i == n - 1) {
                ans++;
                //cout << n - 1 << endl;
            }
        } else if(i == n - 1) {
            if (a[i].second <= max(cur, goalpt) && a[i].second >= min(cur, goalpt)) {
                ans++;
                //cout << i << endl;
            }
        }

        lasttime = curtime;
    }

    

    cout << ans << endl;
    //cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) {
        //cout << "CASE " << t << endl;
        solve();
    }

    return 0;
}