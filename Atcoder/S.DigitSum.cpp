#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;
const int mod = 1e9 + 7;

int solve(int pos, int sumMod, bool tight, string &k, int d, vector<vector<vector<int>>> &dp) {
    if (pos == k.size()) {
        return (sumMod % d) == 0 ? 1 : 0;
    }

    if (dp[pos][sumMod][tight] != -1) {
        return dp[pos][sumMod][tight]; 
    }

    int limit = tight ? k[pos] - '0' : 9;
    int &ans = dp[pos][sumMod][tight];
    ans = 0;
    
    for(int i = 0; i <= limit; i++) {
        bool new_tight = tight && (i == limit);
        ans = (ans + solve(pos+1, (sumMod + i) % d, new_tight, k, d, dp))%mod;
    }
    return ans;
}

void solve() {
    string k; int d;
    cin >> k >> d;
    int n = k.size();
    // pos,sumMod,tight
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (d, vector<int> (2,-1)));
    int result = solve(0,0,1,k,d,dp);
    result = (result  - 1 + mod) % mod;
    cout << result << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}