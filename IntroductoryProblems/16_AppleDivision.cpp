#include<bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<n;i++)
#define ll long long
using namespace std;


void testAll(vector<ll>& elm,ll n,ll sumElm,ll& min,int it=-1,ll sum=0){
    fr(i,it+1,n){
        sum+= elm[i];
        ll m = abs(2*sum-sumElm);
        if(m<min) min=m;
        testAll(elm,n,sumElm,min,i,sum);
        sum-=elm[i];
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> inputs(n);
    ll sumElm=0;
    fr(i, 0, n) {
        cin >> inputs[i];
        sumElm+=inputs[i];
    }
    ll min=LONG_LONG_MAX;
    testAll(inputs,n,sumElm,min);
    cout<<min;
}
