#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

void solving(int readingDuration[],int& n){
    ll sum=0;
    fr(i,0,n-1){
        sum+=(ll)readingDuration[i];
    }
    if(sum<readingDuration[n-1])
        cout<<2*readingDuration[n-1];
    else cout<<sum+(ll)readingDuration[n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int readingDuration[n];
    fr(i,0,n){
        cin>>readingDuration[i];
    }
    sort(readingDuration,readingDuration+n);
    solving(readingDuration,n);
}
