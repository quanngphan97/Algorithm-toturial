#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;
const int mod = 1e9 + 7;



void solve() {
    int n,k; cin >> n >> k;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

//     vector<int> dp(n,1);
//     for(int i = 0; i < k; i++) {
//         vector<int> new_dp(n);
//         for(int j = 0; j < n; j++) {
//             for(int m = 0; m < n; m++) {
//                 if(a[j][m]) {
//                     new_dp[m] += dp[j];
//                     new_dp[m] %= mod;
//                 }
//             }
//         }
//         dp = new_dp;
//     }
//     int ans = 0;
//     for(int i = 0; i < n; i++) {
//         ans += dp[i];
//     }
//     cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}