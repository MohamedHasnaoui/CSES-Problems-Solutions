/**

                            * بسم الله الرحمن الرحيم *

    ﴾ رَبِّ اشْرَحْ لِي صَدْرِي * وَيَسِّرْ لِي أَمْرِي * وَاحْلُلْ عُقْدَةً مِّن لِّسَانِي * يَفْقَهُوا قَوْلِي ﴿

**/
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

int josephusSol(int n,int k){
    if(n==1) return 1;
    if(k<=(n+1)/2){
        if(2*k>n) return (2*k)%n;
        return 2*k;
    }
    int temp = josephusSol(n/2,k-(n+1)/2);
    if(n&1) return 2*temp+1;
    return 2*temp-1;
}

void solving(){
    int n,k;
    cin>>n>>k;
    cout<<josephusSol(n,k)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    while(q--){
        solving();
    }
}