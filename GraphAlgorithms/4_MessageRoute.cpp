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
int previousNode[100001];


int dist[100001];
queue<int> q;
stack<int> st;
void solving(int& n){
    int s = 1;
    q.push(s);
    visited[s]=true;
    dist[s]=1;
    while(!q.empty()){
        s=q.front();
        q.pop();
        for(int u:adj[s]){
            if(visited[u]) continue;
            q.push(u);
            visited[u]=true;
            dist[u]=dist[s]+1;
            previousNode[u]=s;
        }
    }
    if(!visited[n]) {
        cout << "IMPOSSIBLE";
        return;
    }
    cout<<dist[n]<<'\n';
    int k=n;
    st.push(k);
    while(k!=1){
        k=previousNode[k];
        st.push(k);
    }
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
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