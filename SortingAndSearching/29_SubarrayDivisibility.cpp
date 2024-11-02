#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;
void solving(int values[],int& n ){
    unordered_map<ll,ll> mp;
    mp[0]=1;
    ll sum=0ll,res=0ll;
    fr(i,0,n){
        sum+=(ll)values[i];
        int k=(sum%n + n)%n;
        res+=mp[k];
        mp[k]++;
    }
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int values[n];
    fr(i,0,n) cin>>values[i];
    solving(values,n);
}

