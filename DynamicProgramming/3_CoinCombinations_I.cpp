#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
#define modulo 1000000007
using namespace std;
void solving(int& n,int x,int coins[]){
    ll res[x+1];
    res[0]=0;
    fr(i,1,x+1){
        res[i]=0;
        fr(j,0,n){
            if(i-coins[j]>0){
                res[i]= (res[i] + res[i-coins[j]])%modulo;
                continue;
            }
            if(i-coins[j]==0) {
                res[i]=(res[i] + 1)%modulo;
            }
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
