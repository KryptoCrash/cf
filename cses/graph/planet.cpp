/*
https://cses.fi/problemset/task/1750

everything will end up in a cycle at some poll
dfs until you are in a cycle
then calculate k % cycle size and dfs that amount

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, q;
vi t;

int main() {
    cin >> n >> q;

    t = vi(n);

    for (ll i = 0; i < n; i++) {
        cin >> t[i];
        t[i]--;
    }

    for (ll j = 0; j < q; j++) {
        ll x, k;
        cin >> x >> k;
        x--;

        vi path;
        vector<bool> visited(n, false);

        while (true) {
            if (k == 0) {
                cout << x + 1 << endl;
                break;
            }
            if (visited[x]) {
                bool incycle = false;
                ll cycle_size = 0;
                for (ll i : path) {
                    if (i == x) incycle = true;
                    if (incycle) cycle_size++;
                }

                assert(incycle);

                ll left = k % cycle_size;
                for (ll i = 0; i < left; i++) {
                    x = t[x];
                }

                cout << x + 1 << endl;
                break;
            }

            visited[x] = true;
            path.push_back(x);

            x = t[x];
            k--;
        }
    }

    return 0;
}