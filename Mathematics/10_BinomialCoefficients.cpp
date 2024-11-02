/**

                            * بسم الله الرحمن الرحيم *

    ﴾ رَبِّ اشْرَحْ لِي صَدْرِي * وَيَسِّرْ لِي أَمْرِي * وَاحْلُلْ عُقْدَةً مِّن لِّسَانِي * يَفْقَهُوا قَوْلِي ﴿

**/
#include <bits/stdc++.h>
#define ll long long
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fk(l, r) for(ll k=l;k<r;k++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define ln '\n'
using namespace std;
const ll modulo= 1e9+7;
const ll modulo1 = 1e9+6;
ll aPb(ll a,ll b,ll mod){
    if(b==0) return 1ll;
    ll tmp = aPb(a,b/2,mod);
    tmp = (tmp*tmp)%mod;
    if(b&1) tmp = (a*tmp)%mod;
    return tmp;
}
const int maxN = 1e6+1;
ll n;
ll factoriel[maxN];
void build(){
    factoriel[0]=1;
    fi(1,maxN){
        factoriel[i]=(i*factoriel[i-1])%modulo;
    }
}
void solving(){
    int a,b;
    cin>>a>>b;
    ll c = (factoriel[a-b]*factoriel[b])%modulo;
    cout<<(factoriel[a]%c)%modulo<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    build();
    cin>>n;
    while(n--) solving();
}