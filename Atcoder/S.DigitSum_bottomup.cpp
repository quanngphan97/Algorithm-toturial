#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;
const int mod = 1e9 + 7;

void solve() {
    string k; int d;
    cin >> k >> d;
    int n = k.size();
    // pos, sumMod, tight
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(d, vector<int>(2, 0)));
    
    // Review n number of k, sumMod == 0, tight = 0;
    dp[n][0][0] = 1;

    for (int pos = n - 1; pos >= 0; pos--) {
        for (int sumMod = 0; sumMod < d; sumMod++) {
            for (int tight = 0; tight <= 1; tight++) {
                int limit = (tight ? k[pos] - '0' : 9);
                for (int digit = 0; digit <= limit; digit++) {
                    int new_tight = tight && (digit == limit);
                    int new_sumMod = (sumMod + digit) % d;
                    dp[pos][sumMod][tight] += dp[pos + 1][new_sumMod][new_tight];
                    dp[pos][sumMod][tight] %= mod;
                }
            }
        }
    }

    int ans = dp[0][0][1];
    ans = (ans - 1 + mod) % mod;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
