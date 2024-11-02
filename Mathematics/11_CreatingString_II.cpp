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
int countCh[26];
void solving(){
   string s;
   cin>>s;
   int n=s.size();
   for(char ch:s){
       countCh[ch-'a']++;
   }
   ll e=1;
   fi(0,26){
       e=(e*factoriel[countCh[i]])%modulo;
   }
   cout<<(factoriel[n]*aPb(e,modulo-2,modulo))%modulo;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    build();
    solving();
}