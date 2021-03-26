#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define er(n) cout<<"error "<<n<<endl;
int mod = 1000000007;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num_of_items, max_weight;
	cin >> num_of_items >> max_weight;
	int weights[num_of_items], values[num_of_items];
	for (int i = 0 ; i < num_of_items ; i++) {
		cin >> values[i];
	}
	for (int i = 0 ; i < num_of_items ; i++) {
		cin >> weights[i];
	}
	int dp[2][max_weight + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0 ; i < num_of_items ; i++) {
		int row = (i & 1); // 1st, 3rd, 5th .. will go in 1st row and else in 2nd row
		for (int j = 0 ; j <= max_weight ; j++) {
			dp[row][j] = dp[row ^ 1][j]; // going in upper row
			// j is the maximum weight available till now
			if (weights[i] <= j) {
				dp[row][j] = max(dp[row ^ 1][j - weights[i]] + values[i], dp[row][j]);
			}
		}
	}
	// if num of items is odd ans will be in 1st row, otherwise in 2nd row
	cout << dp[num_of_items % 2 == 0][max_weight] << endl;
}
