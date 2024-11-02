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

ll aPb(ll a,ll b){
    if(b==0) return 1ll;
    ll tmp = aPb(a,b/2);
    tmp = (tmp*tmp)%modulo;
    if(b&1) tmp = (a*tmp)%modulo;
    return tmp;
}

int maxNumb = 1000000;
int counts[1000000];
int multiples[1000000];
void solving(ll& n){
    ll result = 0;
    for(ll i=1,j;i<=n;i=j){
        ll elm = n/i;
        j= n/elm +1;
        ll elm1 = ((((i%modulo)*((i-1)%modulo))%modulo)*aPb(2,modulo-2))%modulo;
        ll elm2 = ((((j%modulo)*((j-1)%modulo))%modulo)*aPb(2,modulo-2))%modulo;
        ll elm3 = ((elm2-elm1) + modulo)%modulo;
        result = (result + ((elm%modulo)*elm3)%modulo)%modulo;
    }
    cout<<result;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    solving(n);
}