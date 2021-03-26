#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
int mod=1000000007;

int kadane(int *arr, int n){
	int current_sum=arr[0], best_sum=arr[0];
	for (int i=1 ; i<n ; i++){
		current_sum=max(arr[i], arr[i]+current_sum);
		best_sum=max(best_sum, current_sum);
	}
	return best_sum;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for (int i=0 ; i<n ; i++){
		cin>>arr[i];
	}
    int ans=kadane(arr, n);
    cout<<ans<<endl;
}
