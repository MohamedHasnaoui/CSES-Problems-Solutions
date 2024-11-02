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
bool visited[100001];
bool team1[100001];
bool team2[100001];

void dfs(int s, bool& noSolutions){
    if(visited[s]) return;
    if(noSolutions) return;
    visited[s]=true;
    for(auto u:adj[s]){
        if((team1[s] && team1[u])||(team2[s] && team2[u])){
            noSolutions = true;
            return;
        }
        if(team1[s]) team2[u]=true;
        if(team2[s]) team1[u]=true;
        dfs(u,noSolutions);
    }
}

void solving(int& n){
    bool noSolutions = false;
    for(int i=1;i<=n;i++){
        if(noSolutions) break;
        if(visited[i]) continue;
        team1[i]=true;
        dfs(i,noSolutions);
    }
    if(noSolutions){
        cout<<"IMPOSSIBLE";
        return;
    }
    for(int i=1;i<=n;i++){
        if(team1[i]) cout<<'1'<<' ';
        if(team2[i]) cout<<'2'<<' ';
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    fi(0,m) {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solving(n);
}