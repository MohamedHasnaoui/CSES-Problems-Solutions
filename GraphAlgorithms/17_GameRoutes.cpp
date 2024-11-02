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
vector<int> adj[100001];
bool visited[100001];
int child[100001];
int dp[100001];
stack<int> st;
priority_queue<pair<int,int>> q;

void dfs(int s){
    visited[s]=true;
    for(int u:adj[s]){
        if(!visited[u])
            dfs(u);
        dp[s]=(dp[u]+dp[s])%modulo;
    }
}


void solving(int& n){
    dp[n]=1;
    dfs(1);
    cout<<dp[1];
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
    }

    solving(n);
}