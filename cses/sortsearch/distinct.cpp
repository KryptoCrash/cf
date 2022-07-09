#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n;

int main() {
    cin >> n;

    set<int> a;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.insert(t);
    }

    cout << a.size() << endl;

    return 0;
}