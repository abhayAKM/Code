#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define pi pair<int, int>
#define PI 3.14159265
#define all(x) x.begin(),x.end()
#define er(n) cout << "error " << n << endl;
#define pbds tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define mod 1000000007

void dfs(int st, vi *g, stack<int> &s, bool *vis) {
	vis[st] = 1;
	for (int i : g[st]) {
		if (!vis[i]) {
			dfs(i, g, s, vis);
		}
	}
	s.push(st);
}

void dfs2(int st, vi *g, bool *vis) {
	vis[st] = 1;
	for (int i : g[st]) {
		if (!vis[i]) {
			dfs2(i, g, vis);
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, e;
	cin >> n >> e;
	vi g[n + 1];
	vi gt[n + 1];
	while (e--) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		gt[y].pb(x);
	}
	bool vis[n + 1] = {0};
	stack<int> s;
	for (int i = 1 ; i <= n ; i++) {
		if (!vis[i]) {
			dfs(i, g, s, vis);
		}
	}
	int ans = 0;
	fill(vis, vis + n + 1, 0);
	while (!s.empty()) {
		int st = s.top();
		s.pop();
		if (vis[st]) continue;
		dfs2(st, gt, vis);
		ans++;
	}
	cout << "Total Number of Strongly Connected Component are: " << ans << endl;
	return 0;
}
