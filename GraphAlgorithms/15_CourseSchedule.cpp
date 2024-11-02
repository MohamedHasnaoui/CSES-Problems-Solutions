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
int visited1[100001];
bool NoSolution;
stack<int> st;
void dfs(int s){
    if(NoSolution) return;
    for(auto u:adj[s]){
        if(visited1[u]==2) continue;
        if(visited1[u]==1) {
            NoSolution=true;
            return;
        }
        visited1[u]=1;
        dfs(u);
        visited1[u]=2;
        st.push(u);
        if(NoSolution) return;
    }
}

void solving(int& n){
    for(int i=1;i<=n;i++){
        if(NoSolution) break;
        if(visited1[i]==2) continue;
        visited1[i]=1;
        dfs(i);
        visited1[i]=2;
        st.push(i);
    }
    if(!NoSolution){
        while(!st.empty()) {
            cout<<st.top()<<' ';
            st.pop();
        }
        return;
    }
    cout<<"IMPOSSIBLE";
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