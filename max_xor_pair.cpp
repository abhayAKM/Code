#include <bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    trieNode* left;
    trieNode* right;
    trieNode(){
    left=NULL;
    right=NULL;
    }
};

void insert(int n, trieNode *root){
    trieNode *cur=root;
    for (int i=31 ; i>=0 ; i--){
        int b=(n>>i)&1;
        if (b==0){
            if (!cur->left){
                cur->left=new trieNode();
            }
            cur=cur->left;
        }
        else {
            if (!cur->right){
                cur->right=new trieNode();
            }
            cur=cur->right;
        }
    }
}

int findMaxXorPair(trieNode *root, int *arr, int n){
    int max_xor=0;
    for (int i=0 ; i<n ; i++){
        trieNode *cur=root;
        int val=arr[i], curr_xor=0;
        for (int j=31 ; j>=0 ; j--){
            int b=(val>>j)&1;
            if (b==0){
                if (cur->right){
                    cur=cur->right;
                    curr_xor+=(1<<j);
                }
                else {
                    cur=cur->left;
                }
            }
            else {
                if (cur->left){
                    cur=cur->left;
                    curr_xor+=(1<<j);
                }
                else {
                    cur=cur->right;
                }
            }
        }
        max_xor=max(max_xor, curr_xor);
    }
    return max_xor;
}

 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for (int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    trieNode root;
    for (int i=0 ; i<n ; i++){
        insert(arr[i], &root);
    }
    cout<<findMaxXorPair(&root, arr, n)<<endl;
    return 0;
}
