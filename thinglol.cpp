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

    ll n, m;
    cin >> n >> m;

    vector<set<ll>> ed(n);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;

        ed[a].insert(b);
        ed[b].insert(a);
    }

    bool imp = false;
    vi col(n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || (ed[i].find(0) == ed[i].end())) col[i] = 1;
    }

    ll lst = -1;
    for (int j = 0; j < n; j++) {
        if (col[j] != 1) lst = j;
    }

    if (lst == -1) imp = true;

    for (int i = 0; i < n; i++) {
        if (i == lst || (ed[i].find(lst) == ed[i].end())) col[i] = 2;
    }

    ll lst2 = -1;
    for (int j = 0; j < n; j++) {
        if (col[j] != 1 && col[j] != 2) lst2 = j;
    }

    if(lst2 == -1) imp = true;

    for (int i = 0; i < n; i++) {
        if (i == lst2 || (ed[i].find(lst2) == ed[i].end())) col[i] = 3;
    }

    ll c1, c2, c3;
    c1 = c2 = c3 = 0;

    for (int i = 0; i < n; i++) {
        if (col[i] == 0) imp = true;
        if (col[i] == 1) c1++;
        if (col[i] == 2) c2++;
        if (col[i] == 3) c3++;
    }

    for (int i = 0; i < n; i++) {
        ll a, b, c;
        a = b = c = 0;
        for(int ch : ed[i]) {
            if (col[ch] == 1) a++;
            if (col[ch] == 2) b++;
            if (col[ch] == 3) c++;
        }
        if (col[i] == 1) {
            if (a > 0 || b != c2 || c != c3) imp = true;
        }
        if (col[i] == 2) {
            if (b > 0 || a != c1 || c != c3) imp = true;
        }
        if (col[i] == 3) {
            if (c > 0 || a != c1 || b != c2) imp = true;
        }
    }

    if(imp) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) cout << col[i] << " ";
        cout << endl;
    }

    return 0;
}