#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;
void solving(vector<int>& values,map<int,int> elmIndex,int n){
    int res=1;
    fr(i,0,n){
        if(elmIndex[values[i]+1]<i && values[i]!=n) res++;
    }
    cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> values(n);
    map<int,int> elmIndex;
    fr(i,0,n){
        cin>>values[i];
        elmIndex[values[i]]=i;
    }
    solving(values,elmIndex,n);
}