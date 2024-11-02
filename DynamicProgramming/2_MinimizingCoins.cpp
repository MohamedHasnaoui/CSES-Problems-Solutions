#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
#define maxValue 1000001
using namespace std;
int m=1000001;
void solving(int& n,int x,int coins[]){
    int res[x+1];
    res[0]=0;
    fr(i,1,x+1){
        res[i]=maxValue;
        fr(j,0,n){
            if(i-coins[j]>=0)
                res[i]=min(res[i],res[i-coins[j]]+1);
        }
    }
    if(res[x]==maxValue) {
        cout<<-1;
        return;
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
