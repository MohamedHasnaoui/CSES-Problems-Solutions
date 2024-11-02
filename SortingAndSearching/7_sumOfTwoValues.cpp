#include <bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;
void solving(vector<int>& values,int n,int x,map<int,stack<int>> originalIndices){
    fr(i,0,n){
        int k= upper_bound(values.begin(),values.end(),x-values[i])-values.begin()-1;
        if(k<n &&  k>=0 && k!=i  && x==values[i]+values[k]) {
            cout << originalIndices[values[i]].top()+1<<' ';
            originalIndices[values[i]].pop();
            cout << originalIndices[values[k]].top()+1;
            return;
        }
    }
    cout << "IMPOSSIBLE";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int> values(n);
    map<int,stack<int>> originalIndices;
    fr(i,0,n){
        cin>>values[i];
        originalIndices[values[i]].push(i);
    }
    sort(values.begin(),values.end());
    solving(values,n,x,originalIndices);
}