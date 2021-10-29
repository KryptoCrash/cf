#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    
    cout << (s / (n / 2 + 1)) << endl;
}

int main() {
    int t;
    
    cin >> t;
    
    for(int i = 1; i <= t; i++) solve();
    
    return 0;
}
