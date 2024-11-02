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
double dp[101][601];
ll aPn(ll a,ll n){
    if(n==1) return a;
    ll tmp = aPn(a,n/2);
    tmp*=tmp;
    if(n&1) tmp*=a;
    return tmp;
}
void build(ll n){
    fi(1,7) dp[1][i]=1.0/6;
    fi(2,n+1){
        fj(i,6*i+1){
            fk(1,7) if(j>k) dp[i][j]+=dp[i-1][j-k]*(1.0/6);
        }
    }
}
void solving(){
    ll n,a,b;
    cin>>n>>a>>b;
    build(n);
    double total=0.0;
    fi(a,b+1){
        total+=dp[n][i];
    }
    cout << fixed << setprecision(6);
    cout<<total ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solving();
}