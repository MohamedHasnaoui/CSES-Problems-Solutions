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

int maxNumb = 1000000;
int counts[1000000];
ll arr[100000][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll k;
    cin>>k;
    ll p,a;
    ll n=1;
    ll number=1,number1=1;
    ll sigma=1;
    bool found = false;
    fi(0,k){
        cin>>arr[i][0]>>arr[i][1];
    }
    fi(0,k){
        p=arr[i][0];a=arr[i][1];
        ll pow = aPb(p,a,modulo);
        n = (n*pow)%modulo;
        number=(number*(a+1))%modulo;
        if(a&1 && !found){
            a=(a+1)/2 -1;
            found = true;
        }
        number1=(number1*(a+1))%modulo1;
        sigma=(sigma*((((pow*p)%modulo-1+modulo)%modulo)*aPb(p-1,modulo-2,modulo)%modulo)%modulo)%modulo;
    }
    ll mu = 1;
    if(found) mu = aPb(n,number1,modulo);
    else {
        fi(0, k) {
            mu = (mu * aPb(arr[i][0],arr[i][1]*number1/2,modulo))%modulo;
        }
    }
    cout<<number<<' '<<sigma<<' '<<mu<<' ';
}