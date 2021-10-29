#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("censor.in");
    ofstream fout("censor.out");
    string s;
    string t;

    fin >> s >> t;

    stack<int> st;
    st.push(0);

    vector<vector<int> > max_pre(t.length(), vector<int>(26, 0));

    for (int i = 0; i < t.length(); i++) {
        for (int c = 0; c < 26; c++) {
            max_pre[i][c] = max_pre[max_pre[i - 1][t[i]]][c] + 1;
        }
    }

    string ans;

    for (int i = 0; i < s.length(); i++) {
        int lst = st.top();

        if (lst == t.length()) {
            for (int j = 0; j < t.length(); j++) {
                st.pop();
                ans.pop_back();
            }
        } else {
            st.push(max_pre[lst][s[i] - '0']);
            ans += s[i];
        }
    }

    fout << ans << endl;

    return 0;
}