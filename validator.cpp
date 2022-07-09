#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
ll r, c, n, m;
cin >> r >> c >> n >> m;

set<pair<ll, ll>> s;
for(int i = 0; i < n; i++) {
ll x, y;
cin >> x >> y;
if(s.find({x, y}) != s.end()) return 1;
s.insert({x, y});
}

for(int i = 0; i < m; i++) {
ll x, y;
cin >> x >> y;
if(s.find({x, y}) != s.end()) return 1;
s.insert({x, y});
}

return 0;
}
