#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    function<int(int, int, bool)> query = [&](int x, int v, bool down) {
        if (v > n) return 0;
        cout << "? ";
        for (int i = 0; i < n; i++) {
            if ((i == x) ^ down)
                cout << v + 1 << " ";
            else
                cout << "1 ";
        }
        cout << endl;
        cout.flush();

        int k;
        cin >> k;
        return k;
    };

    vi ans(n);
    int last = 0;
    int x = 0;
    vector<int> res;
    res.push_back(0);
    while ((last = query(0, ++x, false))) {
        res.push_back(last-1);
    }
    x = 0;
    while ((last = query(0, ++x, true))) {
        res.insert(res.begin(), last-1);
    }
    // x + p_i == n
    // p_i == n - x
    for (int i = 0; i < n; i++) {
        ans[res[i]] = i + 1;
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}