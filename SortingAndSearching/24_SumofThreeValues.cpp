#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

void solving(vector<pair<int,int>>& values,int& n,int target){
   vector<tuple<int,int,int>> sumTwo;
   fr(i,0,n){
       fr(j,i+1,n){
           sumTwo.push_back({values[i].first+values[j].first,values[i].second,values[j].second});
       }
   }
   for(auto elm : sumTwo){
       if(get<0>(elm)<target) {
           pair<int, int> tar1 = {target - get<0>(elm), 0};
           pair<int, int> tar2 = {target - get<0>(elm), INT_MAX};
           int a = lower_bound(values.begin(), values.end(), tar1) - values.begin();
           int b = upper_bound(values.begin(), values.end(), tar2) - values.begin();
           fr(i, a, b) {
               if (values[i].second != get<1>(elm) && values[i].second != get<2>(elm)) {
                   cout << ++values[i].second << ' ' << ++get<1>(elm) << ' ' << ++get<2>(elm);
                   return;
               }
           }
       }
   }
   cout<<"IMPOSSIBLE";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,target;
    cin>>n>>target;
    vector<pair<int,int>> values;
    fr(i,0,n){
        int val;
        cin>>val;
        values.push_back({val,i});
    }
    sort(values.begin(),values.end());
    solving(values,n,target);
}

