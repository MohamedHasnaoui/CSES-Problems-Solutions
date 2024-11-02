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
bool processed[1000000];
char path[1000][1000];
vector<tuple<int,int,int>> adj;
vi graph[10001];
stack<char> st;
vll dist(2501,LONG_LONG_MIN);
vi nodesCycle;
bool visited[2501];
void dfs(int s){
    if (visited[s]) return;
    visited[s]=true;
    for(int elm:graph[s]){
        dfs(elm);
    }
}
void solving(int& n){
    dist[1]=0;
    bool positiveCycle=false;
    fi(1,n+1){
        bool reduced=false;
        for(auto e:adj){
            int a,b,w;
            tie(a,b,w)=e;
            if(dist[a]==LONG_LONG_MIN) continue;
            if(dist[b]<dist[a]+(ll)w){
                dist[b]=dist[a]+(ll)w;
                reduced=true;
                if(i==n) {
                    positiveCycle = true;
                    nodesCycle.push_back(b);
                }
            }
        }
        if(!reduced) break;
    }
    if(!positiveCycle){
        cout<<dist[n];
    }else{
        for(int elm:nodesCycle) {
            dfs(elm);
        }
        if(visited[n]) cout<<-1;
        else cout<<dist[n];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a,b,c;

    fi(0,m) {
        cin>>a>>b>>c;
        adj.push_back({a,b,c});
        graph[a].push_back(b);
    }
    solving(n,m);
}