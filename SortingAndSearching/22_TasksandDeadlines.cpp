#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

void solving(vector<pair<int,int>> &tasks,int& n){
    ll reward=0;
    ll currentTime=0;
    fr(i,0,n){
        currentTime+=(ll)tasks[i].first;
        reward+=(ll)tasks[i].second-currentTime;
    }
    cout<<reward;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> tasks;
    fr(i,0,n){
        int a,b;
        cin>>a>>b;
        tasks.push_back({a,b});
    }
    sort(tasks.begin(),tasks.end());
    solving(tasks,n);
}
