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
vi adj[100001];
vi adjRev[100001];
bool visited[100001];
bool visited2[100001];
vi componnent[100001];
int compteur = 0,nbComp = 1;
int res1,res2;
void dfs1(int s,vector<pair<int,int>>& processTime){
    if(visited[s]) return;
    visited[s]=true;
    processTime[s-1]={++compteur,s};
    for(int nd:adj[s]){
        dfs1(nd,processTime);
    }
    processTime[s-1].first = ++compteur;
}
void dfs2(int s){
    if(visited2[s]) {
        return;
    }
    visited2[s]=true;
    componnent[nbComp].push_back(s);
    for(int u:adjRev[s]){
        dfs2(u);
    }
}
void solving(int& n){
    vector<pair<int,int>> processTime(n);
    fi(1,n+1){
        if(visited[i]) continue;
        dfs1(i,processTime);
    }
    sort(processTime.begin(),processTime.end());
    reverse(processTime.begin(),processTime.end());
    for(auto elm: processTime){
        if(visited2[elm.second]) continue;
        dfs2(elm.second);
        nbComp++;
    }
    nbComp--;
    if(nbComp==1){
        cout<<"YES";
        return;
    }
    cout<<"NO"<<'\n';
    cout<<componnent[2][0]<<' '<<componnent[1][0];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a,b;
    fi(1,m+1) {
        cin>>a>>b;
        adj[a].push_back(b);
        adjRev[b].push_back(a);
    }
    solving(n);
}