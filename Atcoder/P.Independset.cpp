#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

void dfs(int v, int parent, vector<vector<int>> &dp, vector<vector<int>> &g) {
    dp[v][0] = dp[v][1] = 1;
    for(auto x : g[v]) {
        if (x == parent) continue;
        dfs(x,v,dp,g);
        dp[v][0] = (dp[v][0] * ((dp[x][0] + dp[x][1])%mod))%mod;
        dp[v][1] = (dp[v][1] * dp[x][0])%mod;
    }
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n+1);

    for (int i = 1; i < n; i++) {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> dp(n+1,vector<int>(2));
    dfs(1,-1,dp,g);

    cout << (dp[1][0] + dp[1][1]) % mod << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}