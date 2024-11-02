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
const ll A= 911382323;
const ll B = 972663749;
const ll modulo= 1e9+7;
const ll modulo1 = 1e9+6;
const ll maxLen = 2e6+5;
ll aPb(ll a,ll b,ll mod){
    if(b==0) return 1;
    ll tmp = aPb(a,b/2,mod);
    tmp=(tmp*tmp)%mod;
    if(b&1) tmp=(tmp*a)%mod;
    return tmp;
}
void solving(){
    ll n; cin>>n;
    string l; cin>>l;
    ll n1 = l.size();
    if(n1>n) cout<<0;
    else if(n==n1) cout<<1;
    else cout<<(aPb(26,n-n1,modulo)*(n-n1+1))%modulo;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solving();
}