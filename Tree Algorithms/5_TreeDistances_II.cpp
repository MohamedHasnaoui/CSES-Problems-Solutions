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
#define modulo 1000000007
using namespace std;
vi adj[1000000];
ll sum[1000000];
ll counts[1000000];
ll result[1000000];
void dfs1(int s,int p){
    for(int u:adj[s]){
        if(u==p) continue;
        dfs1(u,s);
        sum[s]+=sum[u]+counts[u]+1ll;
        counts[s]+=counts[u]+1ll;
    }
}
void dfs2(int s,int p,int& n){
    for(int u:adj[s]){
        if(u==p) continue;
        result[u]=result[s]-counts[u]+(ll)n-counts[u]-2ll;
        dfs2(u,s,n);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a,b;
    fi(1,n){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,0);
    result[1]=sum[1];
    dfs2(1,0,n);
    fi(1,n+1){
        cout<<result[i]<<' ';
    }
}