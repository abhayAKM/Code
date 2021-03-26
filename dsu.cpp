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

class Dsu{
public:
    int n, *par, *rank;
    Dsu(int numNodes) {
        n = numNodes, par = new int[n + 1], rank = new int[n + 1];
        for (int i = 0 ; i <= n ; i++)
            par[i] = i, rank[i] = 1;
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    bool Union(int x, int y) {
        int lx = find(x), ly = find(y);
        if (lx == ly) return 0;
        if (rank[lx] < rank[ly]) par[lx] = ly;
        else if (rank[lx] > rank[ly]) par[ly] = lx;
        else par[lx] = ly, rank[ly]++;
        return 1;
    }
};

int32_t main(){
    int n; cin >> n;
    Dsu obj(n);
    return 0;
}
