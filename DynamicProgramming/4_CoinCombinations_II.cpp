#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
#define modulo 1000000007
using namespace std;
// for each coin we see if we can constarct a sum using this coin and the coins used before
void solving(int& n,int x,int coins[]){
    vector<ll> res(x+1,0);
    res[0]=1;
    fr(j,0,n){
        fr(i,coins[j],x+1){
            res[i]= (res[i] + res[i-coins[j]])%modulo;
        }
    }
    cout<<res[x];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin>>n>>x;
    int coins[n];
    fr(i,0,n) cin>>coins[i];
    solving(n,x,coins);
}
