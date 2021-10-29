#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
ll s_mx_all = 0;
 
ll query(ll l, ll r) {
    if(l == r) return s_mx_all;
    ll s_mx_ind = 0;
    cout << "? " << l << " " << r << endl;
    cout.flush();
 
    cin >> s_mx_ind;
    return s_mx_ind;
}
 
int main(int argc, char const *argv[]) {
    ll n;
    cin >> n;
 
    ll l = 1;
    ll r = n;
 
    s_mx_all = query(l, r);
 
    // For size 2
    if(n == 2) {
        if(s_mx_all == 1) {
            cout << "! 2" << endl;
        } else {
            cout << "! 1" << endl;
        }
 
        return 0;
    }
 
    // Check which side max is on
 
    // Right side
    if(s_mx_all == 1) {
        ll lo = s_mx_all + 1;
        ll hi = n;
        
        while(lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            if(query(s_mx_all, mid) == s_mx_all) { 
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
 
        if(query(s_mx_all, hi) == s_mx_all) cout << "! " << hi << endl;
        else cout << "! " << hi + 1 << endl;
    } else if(s_mx_all == n) {
        ll lo = 1;
        ll hi = s_mx_all - 1;
        
        while(lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            if(query(mid, s_mx_all) == s_mx_all) { 
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
 
        cout << "! " << lo << endl;
    } else if(query(s_mx_all, r) == s_mx_all) {
        ll lo = s_mx_all + 1;
        ll hi = n;
        
        while(lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            if(query(s_mx_all, mid) == s_mx_all) { 
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
 
        if(query(s_mx_all, hi) == s_mx_all) cout << "! " << hi << endl;
        else cout << "! " << hi + 1 << endl;
    } else {
        ll lo = 1;
        ll hi = s_mx_all - 1;
        
        while(lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            if(query(mid, s_mx_all) == s_mx_all) { 
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
 
        cout << "! " << lo << endl;
    }
 
    return 0;
}