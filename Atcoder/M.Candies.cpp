#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int n,k;
    int mod = 1e9 + 7;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i-1][j] += dp[i-1][j-1];
        }
        
        for(int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - a[i] > 0) dp[i][j] -= dp[i-1][j-a[i]-1]; 
            dp[i][j] = ((dp[i][j] %mod) + mod) % mod;
        }
    }

    cout << dp[n][k] << endl;
}