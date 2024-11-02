#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;
void solving(vector<ll>& values,int n){
    int median= values[(n-1)/2];
    ll res=0;
    fr(i,0,n){
        res+=(ll)abs(median-values[i]);
    }
    cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<ll> values(n);
    fr(i,0,n){
        cin>>values[i];
    }
    sort(values.begin(),values.end());
    solving(values,n);
}