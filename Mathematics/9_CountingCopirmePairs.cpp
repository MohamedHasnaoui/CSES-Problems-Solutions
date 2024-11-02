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
ll arr[maxN];
vector<vi> sieve(maxN);
vi primeDivesorsOf(maxN);
vi valuesDivisibleBy(maxN);
void generateSieve(){
    fi(2,maxN){
        if(!sieve[i].empty()) continue;
        for(int x=i;x<=maxN;x+=i){
            sieve[x].push_back(i);
        }
    }
}
void solving(){
    generateSieve();
    fi(0,n){
        fj(1,(1<<(sieve[arr[i]].size()))){
            int nbDiv=0;
            int pr = 1;
          fk(0,sieve[arr[i]].size()){
              if(j&(1<<k)){
                  nbDiv++;
                  pr*=sieve[arr[i]][k];
              }
          }
          valuesDivisibleBy[pr]++;
          primeDivesorsOf[pr]=nbDiv;
        }
    }
    ll validPairs=0;
    fi(0,maxN){
        ll nb = ((ll)(valuesDivisibleBy[i]-1)*(ll)valuesDivisibleBy[i])/2;
        if(!(primeDivesorsOf[i]&1)) nb*=-1;
        validPairs+=nb;
    }
    ll allPairs=((ll)n*(ll)(n-1))/2;
    cout<<allPairs-validPairs;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    fi(0,n){
        cin>>arr[i];
    }
    solving();
}