#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 8;

using pi = pair<int, int>;

struct cmp {
    bool operator()(pi a, pi b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
};

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;

    set<pi, cmp> lo;
    int cnt[maxn];
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < k; i++) {
        lo.insert({i, 0});
    }

    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        q %= k;
        lo.erase({q, cnt[q]});
        cnt[q]++;
        lo.insert({q, cnt[q]});

        cout << lo.begin()->second * k + lo.begin()->first << endl;
    }

    return 0;
}