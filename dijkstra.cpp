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

void dijkstra(int src, vector<pi> *graph, int n) {
	int weight[n];
	bool vis[n] = {0};
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({0, src});
	while (!pq.empty()) {
		pi p = pq.top();
		pq.pop();
		if (vis[p.S]) continue;
		weight[p.S] = p.F;
		vis[p.S] = 1;
		for (pi i : graph[p.S]) {
			if (!vis[i.F])
				pq.push({p.F + i.S, i.F});
		}
	}
	for (int i = 0 ; i < n ; i++) {
		cout << i << ' ' << weight[i] << endl;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, e; cin >> n >> e;
	vector<pi> graph[n];
	while (e--) {
		int x, y, z; cin >> x >> y >> z;
		graph[x].pb({y, z});
		graph[y].pb({x, z});
	}
	dijkstra(0, graph, n);
	return 0;
}
