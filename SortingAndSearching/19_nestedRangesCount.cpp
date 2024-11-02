#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        indexed_set;
bool comp(tuple<int,int,int>& tuple1,tuple<int,int,int>& tuple2){
    if(get<0>(tuple1)==get<0>(tuple2)) return get<1>(tuple1)>get<1>(tuple2);
    else return get<0>(tuple1)<get<0>(tuple2);
}


void solving(int& n,vector<tuple<int,int,int>>& ranges,indexed_set& lasts){
    vector<int> containe(n, 0),contained(n,0);
    indexed_set tmp = lasts;
    fr(i,0,n){
        tuple<int,int,int> range=ranges[i];
        lasts.erase({get<1>(range), get<2>(range)});
        if(!lasts.empty()) {
            auto it = lasts.upper_bound({get<1>(range),INT_MAX});
            if(it!=lasts.begin()) {
                it--;
                containe[get<2>(range)] = lasts.order_of_key(*it) + 1;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        tuple<int,int,int> range=ranges[i];
        tmp.erase({get<1>(range), get<2>(range)});
        auto it=tmp.lower_bound({get<1>(range), 0});
        if(it!=tmp.end()){
            contained[get<2>(range)]= tmp.size()-tmp.order_of_key(*it);
        }
    }
    fr(i,0,n){
        cout<<(int)containe[i]<<' ';
    }
    cout<<'\n';
    fr(i,0,n){
        cout<<(int)contained[i]<<' ';
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> ranges;
    indexed_set lasts;
    fr(i, 0, n) {
        int a, b;
        cin >> a >> b;
        ranges.push_back({a, b, i});
        lasts.insert({b, i});
    }
    sort(ranges.begin(), ranges.end(), comp);
    solving(n, ranges, lasts);
}