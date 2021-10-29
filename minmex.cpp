#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    string s;
    cin >> s;
    
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '0') {
            if(i == 0 || s[i - 1] != '0') ans++;
        }
    }
    
    cout << min(ans, 2) << endl;
}
 
int main() {
    int t;
    
    cin >> t;
    
    for(int i = 1; i <= t; i++) solve();
    
    return 0;
}
