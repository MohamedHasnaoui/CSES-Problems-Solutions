#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

void solving(int coines[],int& n){
    ll res=0;
    fr(i,0,n){
        if(coines[i]>res+1) break;
        res+=(ll)coines[i];
    }
    cout<<res+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int coines[n];
    fr(i,0,n){
        cin>>coines[i];
    }
    sort(coines,coines+n);
    solving(coines,n);
}