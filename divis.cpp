#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    int n;
    int i;
    int a;
    int dv;
    while(t--) {
        cin >> n;
        bool done = false;
        for(i = 1; i <= n; i++) {
            cin >> a;
            
            if(done) continue;
            for(dv = i + 1; a % dv == 0; dv--) {
                if(dv < 2) done = true;
            }
        }
        
        cout << (done ? "NO" : "YES") << endl;
    }
    
    return 0;
}
