#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dp[1000]={0};
int minCost(int arr[][100], int n, int p, int mask){
    if (p>=n){
        return 0;
    }
    if (dp[mask]>0){
        return dp[mask];
    }
    int minimum=INT_MAX;
    for (int i=0 ; i<n ; i++){
        if (!(mask&(1<<i))){
            int ans=minCost(arr, n, p+1, mask|(1<<i))+arr[p][i];
            if (ans<minimum){
                minimum=ans;
            }
        }
    }
    dp[mask]=minimum;
    return minimum;
}

int main() {
   int n;
   cin>>n;
   int arr[100][100];
   for (int i=0 ; i<n ; i++){
    for (int j=0 ; j<n ; j++){
        cin>>arr[i][j];
    }
   }
   cout<<minCost(arr, n, 0, 0)<<endl;
   for (int i=0 ; i<16 ; i+=4){
    cout<<dp[i]<<" "<<dp[i+1]<<" "<<dp[i+2]<<" "<<dp[i+3]<<endl;
   }
}
