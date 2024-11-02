#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

bool comp(pair<int,int>& a,pair<int,int>& b){
    if(a.second==b.second) return a.first<b.first;
    else return a.second<b.second;
}

void solving(vector<pair<int,int>> values,int& n ,int& k){
    multiset<int> endTime;
    endTime.insert(values[0].second);
    int res=1;
    fr(i,1,n){
        auto it= endTime.upper_bound(values[i].first);
        if(it!=endTime.begin()) {
            res++;
            it--;
            endTime.erase(it);
            endTime.insert(values[i].second);
        }else if(endTime.size()!=k){
            endTime.insert(values[i].second);
            res++;
        }
    }
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> values;
    int a,b;
    fr(i,0,n) {
        cin >> a >>b;
        values.push_back({a,b});
    }
    sort(values.begin(),values.end(),comp);
    solving(values,n,k);
}
