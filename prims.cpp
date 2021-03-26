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

int n, e;
vector<pi> graph[10001];

class cmp {
public:
	bool operator()(pi &a, pi &b) {
		return b.S < a.S;
	}
};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> e;
	for (int i = 0 ; i < e ; i++) {
		int x, y, z; cin >> x >> y >> z;
		graph[x].pb({y, z});
		graph[y].pb({x, z});
	}
	bool vis[n + 1] = {0};
	priority_queue<pi, vector<pi>, cmp> pq;
	pq.push({1, 0});
	int ans = 0;
	while (n--) {
		pi p = pq.top();
		pq.pop();
		if (!vis[p.F])
			ans += p.S;
		else continue;
		vis[p.F] = 1;
		for (pi i : graph[p.F]) {
			if (!vis[i.F]) {
				pq.push({i.F, i.S});
			}
		}
	}
	cout << ans << endl;
	return 0;
}
