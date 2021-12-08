#include <bits/stdc++.h>
using namespace std;

using ll = int;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

class ReconstructPermutation {
    public:
    vector<int> reconstruct(int n, vector<int> partial) {
        set<ll> left;
        for(int i = 0; i < n; i++) {
            left.insert(i);
        }

        for(int i : partial) {
            left.erase(i);
        }

        int j = 0;
        int k = 0;
        vi path(n, -1);
        for (int i : left) {
            cout << i << endl;
            if (j == partial.size() || i < partial[j]) {
                path[k++] = i;
                continue;
            }
            while(!(i < partial[j])) {
                path[k++] = partial[j++];
                if (j == partial.size()) break;
            }
        }

        return path;
    }
};