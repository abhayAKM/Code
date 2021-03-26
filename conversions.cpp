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

int bin_to_dec(string &s) {
	int ans = 0;
	for (int i = 0 ; i < s.size() ; i++) {
		ans *= 2;
		ans += s[i] - '0';
	}
	return ans;
}

string dec_to_bin(int n) {
	if (n == 0) return "0";
	int cnt = ceil(log2(n + 1));
	string ans = string(cnt, '0');
	while (n) {
		cnt--;
		if (n & 1) ans[cnt] = '1';
		n /= 2;
	}
	return ans;
}

int32_t main() {
	Abhay();
	string s = "1010";
	cout << bin_to_dec(s) << endl;
	cout << dec_to_bin(25) << endl;
	return 0;
}