#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef local
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 55
#endif
const int N = 5005;
int a[N], dp[N][N], nxt[N], pos[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        //??
        for (int i = 1; i <= n + 1; i++) pos[i] = n + 1;
        //input
        for (int i = 1; i <= n; i++) cin >> a[i];

        // pos[i] = position of color i?
        // nxt[i] = next index of color a[i]
        for (int i = n; i >= 1; i--) {
            nxt[i] = pos[a[i]];
            pos[a[i]] = i;
        }

        // init dp
        for (int i = 1; i <= n; i++) dp[i][i] = 0;

        // range dp
        for (int i = n; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) {
                // worst case (also pull dp)
                dp[i][j] = 1e9;

                // what
                // this is probably for something
                // dp[i][j] is to get everything in the interval to be same color so it only needs to set everything in dp i+1-j to color of a[i] which is just one more op
                //dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                for (int p = nxt[i]; p <= j; p = nxt[p]) {
                    // loop thru all of same color in i - j
                    // although sometimes it is better to use things because they exist
                    // for example if there is already something then we should use it because there is no point to change it

                    // when does this happen is also a good question
                    // probably when there are some colors in the range that we set everything to
                    // so if there is color c in i - j then probably some subranges are already best when set to i-j
                    // also notice that ranges have to be one of the colors of the outmost things
                    // so if they are diff then just say that you can use either the first or second way to get a range
                    // actually it seems that you dont need to worry about the seocond way and only use the first
                    // why
                    // prove that you only need to use the first element of a range as the color of that range for optimal
                    // first for a size 1 thing it is easy to see that it works
                    // next assume we have some range i - j
                    // if we want to set the range to color c it is necessary that something with this color is already in it
                    // but actually we dont have to split this into 3 ranges tho
                    // this is because it is obvious that we want to change all the other ranges to some value
                    // we want to set them to c so there is no reason not to
                    // so the answer is just the amount of time it takes to set first and last range to c
                    // now we prove that this is same for optimal way
                    // first assume this is the case for smaller ranges
                    // also note that last way actually only had two ranges
                    // one was starting with c so it is the same as this method
                    // so we say they are the same
                    // other didnt always start with c
                    // so its + 1 for that one
                    // but if they both started then we could just use both like normal
                    // but now its non optimal
                    // so now we can just translate the other mehtod to the thing used above
                    // instead of starting from anywhere just start from the i + 1th char and add 1
                    // maybe we dont even have to use the second dp statement????
                    // ok maybe its not optimal bc its a diff color
                    


                    //	debug(i, j, p, dp[i][p - 1], dp[p][j]);
                    //split at this color?
                    dp[i][j] = min(dp[i][j], dp[i][p - 1] + dp[p][j]);
                }
                //debug(i, j, dp[i][j]);
            }
        }
        cout << dp[1][n] << '\n';
    }
    return 0;
}