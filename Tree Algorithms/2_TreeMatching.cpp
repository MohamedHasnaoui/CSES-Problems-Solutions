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
bool val[1000000];
int res=0;
void dfs(int s,int p){
    if(adj[s].size()==1 && s!=1){
        val[s]= true;
        return;
    }
    bool v= false;
    for(int u:adj[s]){
        if(u==p) continue;
        dfs(u,s);
        v = v || val[u];
    }
    if(v){
        res++;
        val[s]= false;
        return;
    }
    val[s]=true;
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
    dfs(1,0);
    cout<<res;
}