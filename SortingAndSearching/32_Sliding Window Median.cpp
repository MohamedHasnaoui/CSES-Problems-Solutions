#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
tree_order_statistics_node_update>
indexed_set;

void solving(int values[],int& n ,int& k){
    int first=0,last = k-1;
    int indexMedian = (k-1)/2;
    indexed_set window;
    fr(i,0,last) window.insert({values[i], i});
    while(last!=n){
        window.insert({values[last],last});
        cout<<window.find_by_order(indexMedian)->first<<' ';
        window.erase({values[first],first});
        last++,first++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int values[n];
    fr(i,0,n) {
        cin >> values[i];
    }
    solving(values,n,k);
}
