    #include <bits/stdc++.h>
    using namespace std;
     
    void solve() {
        int n, m;
        cin >> n >> m;
        
        vector<int> p(n + 1);
        for(int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            
            p[i] = p[i - 1] + a;
        }
        
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if(p[b] - p[a - 1] > 0) ans += p[b] - p[a - 1];
        }
        
        cout << ans << endl;
    }
     
    int main() {
        int t;
        cin >> t;
        while(t--) solve();
        
        return 0;
    }
