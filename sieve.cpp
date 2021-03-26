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

void sieve(int n, vi &v){
	bool arr[n+1];
	for (int i=1 ; i<=n ; i++){
		arr[i]=1;
	}
	for (int i=2 ; i*i<=n ; i++){
		if (arr[i]){
			for (int j=i*i ; j<=n ; j+=i){
				arr[j]=0;
			}
		}
	}
	for (int i=2 ; i<=n ; i++){
		if (arr[i]) v.pb(i);
	}
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    vi v;
    sieve(n, v);
    for (int i: v) cout<<i<<" ";
    cout<<endl;
    return 0;
}
