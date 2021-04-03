#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

int main(){
    tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> s;
    for (int i=10 ; i>0 ; i--){
        s.insert(i);
    }
    auto it=s.find_by_order(5); // give iterator of 5th index (0 based indexing)
    cout<<*it<<endl;

    cout<<s.order_of_key(6)<<endl; // count of keys strictly less than 6

    if (s.find(5)!=s.end()){  // no .count() fxn available
        s.erase(5);
    }

    for (auto it=s.begin() ; it!=s.end() ; it++){
        cout<<*it<<"  ";
    }
}
