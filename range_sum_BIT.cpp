#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define er(n) cout << "error " << n << endl;
int mod = 1000000007;

void update(int *bit, int idx, int val, int n){
    cout<<idx<<" : ";
    for ( ; idx<=n ; idx+=idx&-idx){
        bit[idx]+=val;
        cout<<idx<<" ";
    }
    cout<<endl;
}

int query(int *bit, int idx){
    int sum=0;
    for ( ; idx>0 ; idx-=(idx&(-idx))){
        sum+=bit[idx];
    }
    return sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n+1], bit[n+1]={0};
    for (int i=1 ; i<=n ; i++){
        cin>>arr[i];
    }
    for (int i=1 ; i<=n ; i++){
        update(bit, i, arr[i], n);
    }
    for (int i=1 ; i<=n ; i++){
        cout<<bit[i]<<" ";
    } cout<<endl;
    int q; cin>>q;
    while (q--){
        int l, r;
        cin>>l>>r;
        int sum=query(bit, r);
        sum-=query(bit, l-1);
        cout<<"Sum of elements is: "<<sum<<endl;
    }
    return 0;
}
