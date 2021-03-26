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

int32_t main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int i = 0, j = 0, ans = 0;
		int fre[26] = {0};
		bool rep = 0;
		while (j < s.size()) {
			if (!rep) {
				if (fre[s[j] - 'a']) rep = 1;
				else ans = max(ans, j - i + 1);
				fre[s[j++] - 'a']++;
			}
			else {
				if (fre[s[i] - 'a'] > 1) rep = 0;
				fre[s[i++] - 'a']--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
