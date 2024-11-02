#include <bits/stdc++.h>
#define ll long long
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define modulo 1000000007
using namespace std;

void solving(ll prefixsum[]){
    int a,b;
    cin>>a>>b;
    cout<<prefixsum[b]-prefixsum[a-1]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int arr[n];
    ll prefixsum[n+1];
    prefixsum[0]=0;
    fi(0,n) {
        cin >> arr[i];
        prefixsum[i+1]=prefixsum[i]+(ll)arr[i];
    }
    while(q--)
        solving(prefixsum);
}