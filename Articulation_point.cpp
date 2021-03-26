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

vector<vi> G(100001);
vi disc(100001), low(100001);
vector<bool> vis(100001, 0), arti_point(100001, 0);
int Time = 0, child_count = 0, src = 0;

void dfs(int st, int par) {
    vis[st] = 1;
    disc[st] = low[st] = Time++;
    cout << st << ' ' << disc[st] << ' ' << low[st] << endl;
    for (int i : G[st]) {
        if (i == par) continue;
        if (vis[i]) {
            low[st] = min(low[st], disc[i]);
        }
        else {
            if (st == src) ++child_count;
            dfs(i, st);
            low[st] = min(low[st], low[i]);
            if (st != src && disc[st] <= low[i]) {
                arti_point[st] = 1; // st is ariculation point
                cout << st << " is articulation point\n";
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, e;
    cin >> n >> e;
    for (int i = 1 ; i <= e ; i++) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
    src = 0;
    dfs(0, -1);
    int ans = 0;
    if (child_count > 1) ++ans;
    for (int i = 0 ; i < n ; i++) {
        if (arti_point[i]) ++ans;
    }
    cout << "Number of articulation Point: " << ans << endl;
    return 0;
}
