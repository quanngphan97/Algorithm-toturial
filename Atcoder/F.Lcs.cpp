#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;

void trace(string &ans, vector<vector<int>> &dp, string s, string t, int lens, int lent) {
    if (lens == 0 || lent == 0) return;
    
    if (s[lens - 1] == t[lent - 1]) {
        ans = s[lens - 1] + ans; 
        trace(ans, dp, s, t, lens - 1, lent - 1);
    } else if (dp[lens - 1][lent] > dp[lens][lent - 1]) {
        trace(ans, dp, s, t, lens - 1, lent);
    } else {
        trace(ans, dp, s, t, lens, lent - 1);
    }
}

void solve() {
    string s,t ; cin >> s >> t;
    int lens= s.length(), lent = t.length();
    vector<vector<int>> dp(lens+1, vector<int>(lent+1, 0));
    for(int i = 1; i <= lens; i++) {
        for(int j = 1; j <= lent; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    string ans = "";
    trace(ans,dp,s,t,lens,lent);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
