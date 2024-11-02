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
vector<vector<ll>> M = {{0,1},{1,1}};
vector<vector<ll>> powerM(ll n){
    if(n==0) return {{1,0},{0,1}};
    if(n==1) return M;
    vector<vector<ll>> tmp = powerM(n/2);
    tmp = {{((tmp[0][0]*tmp[0][0])%modulo+(tmp[0][1]*tmp[1][0])%modulo)%modulo,
            ((tmp[0][0]*tmp[0][1])%modulo+(tmp[0][1]*tmp[1][1])%modulo)%modulo
            },
           {

          ( (tmp[1][0] * tmp[0][0])%modulo + (tmp[1][1] * tmp[0][1])%modulo)%modulo,
          (( tmp[1][0] * tmp[0][1])%modulo + (tmp[1][1] * tmp[1][1])%modulo)%modulo
           }};
    if(n&1) {
        tmp = {{(tmp[0][0] * M[0][0] + tmp[0][1] * M[1][0])%modulo,
                      ( tmp[0][0] * M[0][1] + tmp[0][1] * M[1][1])%modulo
               },
               {
                (tmp[1][0] * M[0][0] + tmp[1][1] * M[0][1])%modulo,
                     (  tmp[1][0] * M[0][1] + tmp[1][1] * M[1][1])%modulo
               }};
    }
    return tmp;
};
void solving(){
    ll n; cin>>n;
     cout<<powerM(n)[0][1]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    solving();
}