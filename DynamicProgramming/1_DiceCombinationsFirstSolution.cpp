#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
#define m  1000000007
using namespace std;
void solving(int& n){
    ll sum=0,tab[n+1];
    tab[0]=0;
    fr(i,1,n+1){
        tab[i]=sum;
        if(i<=6) tab[i]++;
        else {
            tab[i] = ((tab[i]- tab[i - 7])%m+m)%m; //for negative reminder
            sum = ((sum- tab[i - 7])%m+m)%m;
        }
        sum=(sum+tab[i])%m;
    }
    cout<<tab[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    solving(n);
}
