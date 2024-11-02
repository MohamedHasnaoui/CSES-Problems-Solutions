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
int parent[100001];
bool foundSolution;
int firstElmCycle;
int lastElmCycle;

void dfs(int s){
    if(foundSolution) return;
    for(auto u:adj[s]){
        if(foundSolution) return;
        if(visited[u]) {
            if(u!=parent[s]) {
                foundSolution = true;
                firstElmCycle = u;
                lastElmCycle = s;
            }
            continue;
        }

        parent[u]=s;
        visited[u]=true;
        dfs(u);
    }
}

void solving(int& n){
    for(int i=1;i<=n;i++){
        if(foundSolution) break;
        if(visited[i]) continue;
        visited[i]=true;
        dfs(i);
    }
    if(foundSolution){
        int elm = parent[lastElmCycle];
        int i=3;
        while(elm!=firstElmCycle) {
            elm = parent[elm];
            i++;
        }
        cout<<i<<'\n';
        cout<<firstElmCycle<<' ';
        cout<<lastElmCycle<<' ';
        elm = parent[lastElmCycle];
        cout<<elm<<' ';
        while(elm!=firstElmCycle) {
            elm = parent[elm];
            cout<<elm<<' ';
        }
    }else{
        cout<<"IMPOSSIBLE";
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