#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;
void solving(vector<ll>& values,int n){
    ll sum=LONG_MIN,max=LONG_MIN;
    fr(i,0,n){
        if(sum<0)sum=values[i];
        else sum+=values[i];
        if(sum>max) max=sum;
    }
    cout<<max;
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
    solving(values,n);
}