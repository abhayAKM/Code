#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define er(n) cout << "error " << n << endl;
int mod = 1000000007;

void prime_factors(int n, vi &v){
    if (n == 1) return;
	for (int i=2 ; i*i<=n && n>1 ; i++){
		while (n%i==0){
			v.pb(i);
			n/=i;
		}
	}
	if (n!=1) v.pb(n);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    vi v;
    prime_factors(n, v);
    for (int i:v) cout<<i<<endl;
    return 0;
}
