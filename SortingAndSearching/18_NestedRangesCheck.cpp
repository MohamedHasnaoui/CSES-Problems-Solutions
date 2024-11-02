#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

bool comp(pair<int,int> pair1,pair<int,int> pair2){
    if(pair1.second==pair2.second) return pair1.first<pair2.first;
    else return pair1.second<pair2.second;
}


void solving(int& n,vector<pair<int,int>>& ranges,map<pair<int,int>,int>& originalIndices,multiset<int> lasts){
    vector<bool> containe(n, false),contained(n,false);
    multiset<int> tmp = lasts;
    for(auto range:ranges){
        lasts.erase(lasts.find(range.second));
        auto it= lasts.lower_bound(range.second);
        if(!(it==lasts.begin() && *it!=range.second)){
            containe[originalIndices[range]]=true;
        }
    }
    for(auto it=ranges.rbegin();it!=ranges.rend();it++){
        tmp.erase(tmp.find(it->second));
        auto it1=tmp.lower_bound(it->second);
        if(it1!=tmp.end()){
            contained[originalIndices[*it]]=true;
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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> ranges;
    map<pair<int,int>,int> originalIndices;
    multiset<int> lasts;
    fr(i,0,n){
        int a,b;
        cin>>a>>b;
        ranges.push_back({a,b});
        originalIndices[{a,b}]=i;
        lasts.insert(b);
    }
    sort(ranges.begin(),ranges.end(),comp);
    solving(n,ranges,originalIndices,lasts);
}
