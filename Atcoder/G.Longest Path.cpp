#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;

void dfs(int i, vector<vector<int>> &g, vector<bool> &vis, vector<int>& ans) {
     for(int node : g[i]) {
        if (!vis[node]) {
            vis[node] = true;
            dfs(node,g,vis,ans);
        }
    }
    ans.push_back(i);
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u,v; cin >> u >> v;
        g[u-1].push_back(v-1);
    }
    
    vector<bool> vis(n,false);
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        dfs(i,g,vis,ans);
    }
    
    int cnt = 0; vector<int> dp(n);
    
    for(auto x : ans) {
        for(auto y : g[x]) {
            dp[x] = max(dp[x],dp[y] + 1);
            cnt = max(cnt,dp[x]);
        }
    }
    cout << cnt << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
