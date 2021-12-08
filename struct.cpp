#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n;

struct cmp {
    bool operator()(const Edge& x, const Edge& y) {
        return x.w < y.w;
    }
};

struct Edge {
    int u, v, w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    set<Edge, cmp> a;

    array<int, 3> blah;

    pi fdgsbf;
    fdgsbf.first;

    cmp a;

    a.x;

    return 0;
}