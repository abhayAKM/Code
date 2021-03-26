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

// This fxn returns 1 if there is -ve weight cycle otherwise returns 0
int bellmanFord(int n, vector<pi> *a) {
	int weight[n];
	fill(weight, weight + n, INT_MAX);
	weight[0] = 0;
	int cnt = n;
	while (cnt--) {
		for (int i = 0 ; i < n ; i++) {
            if (weight[i] == INT_MAX) continue;
			for (pi j : a[i]) {
				int sum = weight[i] + j.S;
				if (cnt == 0 && sum < weight[j.F]) return 1;
				if (sum < weight[j.F]) weight[j.F] = sum;
			}
		}
	}
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, e;
		cin >> n >> e;
		vector<pi> a[n];
		while (e--) {
			int x, y, z; cin >> x >> y >> z;
			a[x].pb({y, z});
		}
		int ans = bellmanFord(n, a);
		cout << ans << endl;
	}
	return 0;
}
