#include <bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;
void solving(vector<pair<int,int>> Times,int n){
    int currentEndingTime=Times[0].first;
    int res=1;
    for(int i=1;i<n;i++){
        if(currentEndingTime<=Times[i].second){
            res++;
            currentEndingTime=Times[i].first;
        }
    }
    cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> Times;
    fr(i,0,n) {
        int ti,tf;
        cin >> ti >> tf;
        Times.push_back({tf,ti});
    }
    sort(Times.begin(), Times.end());
    solving(Times,n);
}