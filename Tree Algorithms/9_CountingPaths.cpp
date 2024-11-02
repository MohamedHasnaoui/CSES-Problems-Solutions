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
vi adj[200001];
ll sum[200001];
ll counts[200001];
const int logK = 18;
ll ancestor[200001][logK];
int level[200001];
int values[200001];
int result[200001];
void dfs(int s,int p) {
    ancestor[s][0]=p;
    for (int u: adj[s]) {
        if(u==p) continue;
        level[u]=level[s]+1;
        dfs(u,s);
    }
}
void dfs2(int s,int p){
    result[s]=values[s];
    for (int u: adj[s]) {
        if(u==p) continue;
        dfs2(u,s);
        values[s] += values[u];
    }
}
void build(int& n){
    fi(1,logK){
        fj(1,n+1){
            ancestor[j][i]=ancestor[ancestor[j][i-1]][i-1];
        }
    }
}
int findAncestor(int a,int b){
    if(b<0) return a;
    fir(logK,0){
        if(b&1<<i){
            a=ancestor[a][i];
        }
    }
    return a;
}
void solving(){
    int a,b;
    cin>>a>>b;
    int node1=a,node2=b;
    if(level[a]!=level[b]){
        if(level[b]>level[a]){
            swap(a,b);
            swap(node1,node2);
        }
        a= findAncestor(a,level[a]-level[b]);
    }
    int lca;
    if(a==b){
        lca = a;
    }
    else {
        fir(logK - 1, 0) {
            if (ancestor[a][i] != ancestor[b][i]) {
                a = ancestor[a][i];
                b = ancestor[b][i];
            }
        }
        lca = ancestor[a][0];
    }
    values[node1]++;
    values[node2]++;
    values[lca]--;
    values[ancestor[lca][0]]--;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int a,b;
    fi(1,n){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    level[1]=1;
    dfs(1,0);
    build(n);
    while(q--){
        solving();
    }
    dfs2(1,0);
    fi(1,n+1){
        cout<<values[i]<<' ';
    }
}