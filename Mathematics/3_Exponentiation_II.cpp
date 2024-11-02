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
using namespace std;
const ll modulo= 1e9+7;

ll aPb(ll& a,ll b,ll m){
    if(b==0) return 1;
    ll r = aPb(a,b/2,m);
    r=(r*r)%m;
    if(b&1) r=(r*a)%m;
    return r;
}

void solving(){
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<aPb(a,aPb(b,c,modulo-1),modulo)<<'\n';
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