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
    sort(sumTwo.begin(),sumTwo.end());
    for(auto elm : sumTwo){
        if(get<0>(elm)<target) {
            tuple<int, int,int> tar1 = {target - get<0>(elm), 0,0};
            tuple<int, int,int> tar2 = {target - get<0>(elm), INT_MAX,INT_MAX};
            int a = lower_bound(sumTwo.begin(), sumTwo.end(), tar1) - sumTwo.begin();
            int b = upper_bound(sumTwo.begin(), sumTwo.end(), tar2) - sumTwo.begin();
            fr(i, a, b) {
                if (get<1>(sumTwo[i]) != get<1>(elm) && get<1>(sumTwo[i]) != get<2>(elm)
                && get<2>(sumTwo[i]) != get<1>(elm) && get<2>(sumTwo[i]) != get<2>(elm)
                ) {
                    cout << ++get<1>(sumTwo[i])<<' '<<++get<2>(sumTwo[i])<< ' ' << ++get<1>(elm) << ' ' << ++get<2>(elm);
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

