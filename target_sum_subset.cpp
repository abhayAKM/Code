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

bool target_sum(int *a, int n, int sum) {
	vector<vector<bool>> dp(2, vector<bool>(sum + 1, 0));
	dp[0][0] = dp[1][0] = 1;
	// dp[i][j] stores if there is any subset till ith index which gives sum as j
	for (int i = 0 ; i < n ; i++) {
		int r = (i & 1);
		for (int j = 0 ; j <= sum ; j++) {
			dp[r][j] = dp[r ^ 1][j];
			if (a[i] <= j && dp[r ^ 1][j - a[i]]) {
				dp[r][j] = 1;
			}
		}
		if (dp[r][sum]) return 1;
	}
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n];
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	int target; cin >> target;
	if (target_sum(a, n, target)) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
