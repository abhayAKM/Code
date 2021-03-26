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

void Abhay() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int n, q, x, y;
int a[100001], tre[400001];

void build(int low, int high, int idx) {
	if (low == high) {
		tre[idx] = a[low];
		return;
	}
	int mid = (low + high) / 2;
	build(low, mid, 2 * idx);
	build(mid + 1, high, 2 * idx + 1);
	tre[idx] = min(tre[2 * idx], tre[2 * idx + 1]);
}

void update(int low, int high, int idx) {
	if (low == high) {
		a[x] = y;
		tre[idx] = y;
		return;
	}
	int mid = (low + high) / 2;
	if (x > mid) update(mid + 1, high, 2 * idx + 1);
	else update(low, mid, 2 * idx);
	tre[idx] = min(tre[2 * idx], tre[2 * idx + 1]);
}

int query(int low, int high, int idx) {
	if (high < x || low > y) {
		return 2e9;
	}
	if (low >= x && high <= y) {
		return tre[idx];
	}
	int mid = (low + high) / 2;
	int left = query(low, mid, 2 * idx);
	int right = query(mid + 1, high, 2 * idx + 1);
	return min(left, right);
}

int32_t main() {
	// Abhay();
	cin >> n >> q;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	build(1, n, 1);
	while (q--) {
		char ch; cin >> ch >> x >> y;
		if (ch == 'q') cout << query(1, n, 1) << endl;
		else update(1, n, 1);
	}
	return 0;
}