#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
#define m 1000000007
using namespace std;
void solving(int& n){
    ll res[n+1];
    res[0]=0;
    fr(i,1,n+1){
        res[i]=0;
        fr(j,1,7){
            if(i-j>0){
                res[i]=(res[i] + res[i-j])%m;
                continue;
            }if(i-j==0)
                res[i]=(res[i] + 1)%m;;
        }
    }
    cout<<res[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    cin>>n;
    solving(n);
}
