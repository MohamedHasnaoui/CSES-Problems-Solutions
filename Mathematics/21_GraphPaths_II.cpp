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
vector<vector<ll>> adj(101,vector<ll>(101,LONG_LONG_MAX));
vector<vector<ll>> I(101,vector<ll>(101));
vector<vector<ll>> aPb(ll n){
    if(n==1) return adj;
    vector<vector<ll>> tmp = aPb(n/2);
    vector<vector<ll>> tmp1(101,vector<ll>(101,LONG_LONG_MAX));
    fi(1,101){
        fj(1,101){
            ll sum = LONG_LONG_MAX;
            fk(1,101){
                if(tmp[i][k]==LONG_LONG_MAX || tmp[k][j]==LONG_LONG_MAX) continue;
                sum = min(sum,(tmp[i][k]+tmp[k][j]));
            }
            tmp1[i][j]=sum;
        }
    }
    tmp = tmp1;
    if(n&1){
        fi(1,101){
            fj(1,101){
                ll sum = LONG_LONG_MAX;
                fk(1,101){
                    if(tmp[i][k]==LONG_LONG_MAX || adj[k][j]==LONG_LONG_MAX) continue;
                    sum = min(sum,(tmp[i][k]+adj[k][j]));
                }
                tmp1[i][j]=sum;
            }
        }
        tmp = tmp1;
    }
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    fi(0,m){
        int a,b,w;
        cin>>a>>b>>w;
        if(w<adj[a][b]) adj[a][b]=w;
    }
    ll res=aPb(k)[1][n];
    if(res==LONG_LONG_MAX) cout<<-1;
    else cout<<res;
}