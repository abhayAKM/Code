// https://www.spoj.com/problems/LCASQ/
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


vi G[10000];
int depth[10000];
int up[10000][14];

void dfs(int st = 0) {
	for (int i : G[st]) {
		depth[i] = depth[st] + 1;
		up[i][0] = st;
		for (int j = 1 ; j < 14 ; j++) {
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
		dfs(i);
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	for (int i = 0 ; i < 14 ; i++) {
		if (diff & (1 << i)) u = up[u][i];
	}
	if (u == v) return u;
	for (int i = 13 ; i >= 0 ; i--) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[u][0];
}

int32_t main() {
	int n; cin >> n;
	for (int i = 0 ; i < n ; i++) {
		int m, j; cin >> m;
		while (m--) {
			cin >> j;
			G[i].pb(j);
		}
	}
	dfs();
	int q; cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
	return 0;
}
