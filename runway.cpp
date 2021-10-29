#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<pair<int, bool>> last_round;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        last_round.insert({a, false});
    }

    vector<vector<int>> round(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> round[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        multiset<pair<int, bool>> new_round;
        for (int j = 0; j < m; j++) {
            auto good = last_round.find({round[i][j], true});
            auto bad = last_round.find({round[i][j], false});
            if (good != last_round.end()) {
                last_round.erase(good);
                new_round.insert({round[i][j], true});
            } else if (bad != last_round.end()) {
                last_round.erase(bad);
                new_round.insert({round[i][j], false});
            } else {
                new_round.insert({round[i][j], true});
            }
        }

        for (auto left_over : last_round) {
            ans += left_over.second;
        }
        last_round.clear();
        last_round = new_round;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}