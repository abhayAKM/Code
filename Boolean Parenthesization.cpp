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

class Solution {
public:
    int countParenth(string &symb, string &oper) {
        int n = symb.size();
        int dp1[n][n] = {}, dp2[n][n] = {};
        for (int g = 0 ; g < n ; g++) {
            for (int i = 0, j = g ; j < n ; i++, j++) {
                if (g == 0) {
                    dp1[i][j] = symb[i] == 'T';
                    dp2[i][j] = symb[i] == 'F';
                }
                else {
                    for (int k = i ; k < j ; k++) {
                        if (oper[k] == '&') {
                            dp1[i][j] += dp1[i][k] * dp1[k + 1][j]; // 1 1
                            dp2[i][j] += dp1[i][k] * dp2[k + 1][j]; // 1 0
                            dp2[i][j] += dp2[i][k] * dp1[k + 1][j]; // 0 1
                            dp2[i][j] += dp2[i][k] * dp2[k + 1][j]; // 0 0
                        }
                        else if (oper[k] == '|') {
                            dp1[i][j] += dp1[i][k] * dp2[k + 1][j]; // 1 0
                            dp1[i][j] += dp2[i][k] * dp1[k + 1][j]; // 0 1
                            dp1[i][j] += dp1[i][k] * dp1[k + 1][j]; // 1 1
                            dp2[i][j] += dp2[i][k] * dp2[k + 1][j]; // 0 0
                        }
                        else {
                            dp1[i][j] += dp1[i][k] * dp2[k + 1][j]; // 1 0
                            dp1[i][j] += dp2[i][k] * dp1[k + 1][j]; // 0 1
                            dp2[i][j] += dp1[i][k] * dp1[k + 1][j]; // 1 1
                            dp2[i][j] += dp2[i][k] * dp2[k + 1][j]; // 0 0
                        }
                    }
                }
            }
        }
        return dp1[0][n - 1];
    }
};

int32_t main() {
    string symb = "TFT";
    string oper = "^&";
    Solution obj;
    cout << obj.countParenth(symb, oper) << endl;
    return 0;
}
