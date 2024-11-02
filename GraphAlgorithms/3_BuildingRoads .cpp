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
stack<int> roads;
void dfs(int s){
    if(visited[s]) return;
    visited[s]=true;
    for(auto u:adj[s]){
        dfs(u);
    }
}

void solving(int& n){
    int res=-1;
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        res++;
        roads.push(i);
        dfs(i);
    }
    cout<<res<<'\n';
    if(res){
        int a,b;
        a=roads.top();
        roads.pop();
        while(!roads.empty()){
            b = roads.top();
            roads.pop();
            cout<<b<<' '<<a<<'\n';
            a=b;
        }
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