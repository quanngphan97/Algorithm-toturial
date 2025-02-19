#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &order, vector<bool> &vis, vector<vector<int>> &g) {
	vis[node] = true;
	for(auto x : g[node]) {
		if(!vis[x]) {
			dfs(x, order, vis, g);
		}
	}
	order.push_back(node);
}

void solve() {
	int n,m; cin >> n >> m;
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i++) {
		int x,y; cin >>  x >> y;
		x--,y--;
		g[x].push_back(y);
	}
	
	vector<bool> vis(n,false);
	
	//topological sort
	vector<int> order;
	for(int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i,order,vis,g);
		}
	}
	
	int cnt = 0; vector<int> dp(n);
	for(auto x : order) {
		for(auto y : g[x]) {
			dp[x] = max(dp[x],dp[y] + 1);
		}
        cnt = max(cnt,dp[x]);
	}
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	solve();
	
	return 0;
}
