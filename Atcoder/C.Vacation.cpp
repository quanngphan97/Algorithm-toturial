#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;

void solve() {
    int n; cin >> n;
    vector<vector<int>> act(n+1,vector<int>(3));
    
    for(int i = 1; i <= n; i++) {
        cin >> act[i][0] >> act[i][1] >> act[i][2];
    }
    
    vector<vector<int>> dp(n+1,vector<int>(3,-oo));
    for(int i = 0; i < 3; i++) {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if (j == k) continue;
                dp[i][j] = max(dp[i][j],act[i][k] + dp[i-1][k]);
            }        
        }
    }
    int ans = -oo;
    for(int i = 0; i < 3; i++) ans = max(ans,dp[n][i]);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}