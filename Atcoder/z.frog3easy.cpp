#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Line {
    int a,b;
    int value(int x) {
        return a*x + b;
    }
}

int square(int x) { 
    return x*x;
}

void solve() {
    int n; cin >> n;
    int c; cin >> c;

    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];

    vector<Line> lines;

    int st = 0;
    for(int i = 0; i<n; i++) {
        while(st <= lines.size() - 2) {
            Line A = lines[st];
            Line B = lines[st+1];

            if (A.value(h[i]) >= B.value(h[i])) {
                st++;
            } else {
                break;
            }
        }

        int best = 0; // dp[i]
        if (i != 0) {
            best = lines[st].value(h[i]) + square(h[i]) + C;
        }

    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
