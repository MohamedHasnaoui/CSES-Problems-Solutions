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
ll n,k;
ll arr[20];
void solving(){
    ll res=0;
    fi(1,(1<<k)){
        ll nbDiv = 0;
        ll tmp = n;
        fj(0,k) {
            if (1<<j & i){
                nbDiv++;
                tmp/=arr[j];
            }
        }
        if(!(nbDiv&1)) tmp*=-1;
        res+=tmp;
    }
    cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    fi(0,k){
        cin>>arr[i];
    }
    solving();
}