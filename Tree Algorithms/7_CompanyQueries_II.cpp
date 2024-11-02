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
void dfs(int s) {
    for (int u: adj[s]) {
        level[u] = level[s] + 1;
        dfs(u);
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
    if(level[a]!=level[b]){
        if(level[b]>level[a]) swap(a,b);
        a= findAncestor(a,level[a]-level[b]);
    }
    if(a==b){
        cout<<a<<'\n';
        return;
    }
    fir(logK-1,0){
        if(ancestor[a][i]!=ancestor[b][i]){
            a=ancestor[a][i];
            b=ancestor[b][i];
        }
    }
    cout<<ancestor[a][0]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    fi(2,n+1){
        cin>>ancestor[i][0];
        adj[ancestor[i][0]].push_back(i);
    }
    build(n);
    level[1]=1;
    dfs(1);
    while(q--){
        solving();
    }
}