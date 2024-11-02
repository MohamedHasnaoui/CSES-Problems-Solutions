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
#define modulo 1000000007
using namespace std;
ll adj[501][501];
ll dist[501][501];
ll INF = LONG_LONG_MAX;
void solving() {
    int a,b;
    cin>>a>>b;
    if(dist[a][b]==INF) cout<<-1<<'\n';
    else cout<<dist[a][b]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    ll a,b,c;
    fi(0,m) {
        cin>>a>>b>>c;
        if(adj[a][b]==0ll || adj[a][b]>c) {
            adj[a][b] = c;
            adj[b][a] = c;
        }
    }
    fi(1,n+1){
        fj(1,n+1){
            if(i==j) dist[i][j]=0ll;
            else if(adj[i][j]) dist[i][j]=adj[i][j];
            else dist[i][j]=INF;
        }
    }
    fk(1,n+1){
        fi(1,n+1){
            fj(1,n+1){
                ll temp = dist[i][k]+dist[k][j];
                if(temp<0) temp = INF;
                dist[i][j]=min(dist[i][j],temp);
            }
        }
    }
    while (q--)
        solving();
}