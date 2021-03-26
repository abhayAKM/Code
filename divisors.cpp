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

void divisors(int n, vi &v) {
	int last = sqrt(n);
	for (int i = 1 ; i < last ; i++) {
		if (n % i == 0) {
			v.pb(i);
			v.pb(n / i);
		}
	}
	if (n % last == 0) {
		v.pb(last);
		if (last * last != n) v.pb(n / last);
	}
}

int32_t main() {
	Abhay();
	int n; cin >> n;
	vi v;
	divisors(n, v);
	for (int i : v) cout << i << ' ';
	return 0;
}