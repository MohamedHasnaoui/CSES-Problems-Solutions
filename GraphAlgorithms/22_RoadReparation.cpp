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
vector<pair<int,int>> adj[100001];
bool processed[100001];
priority_queue<pair<int,int>> q;
void solving(int& n){
    ll result=0ll;
    q.push({0,1});
    while(!q.empty()){
        int w=-q.top().first,a=q.top().second;
        q.pop();
        if(processed[a]) continue;
        processed[a]=true;
        result+=(ll)w;
        for(auto u:adj[a]){
            if(processed[u.first]) continue;
            q.push({-u.second, u.first});
        }
    }
    fi(2,n){
        if(!processed[n]){
            cout<<"IMPOSSIBLE";
            return;
        }
    }
    cout<<result;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a,b,w;
    fi(0,m) {
        cin>>a>>b>>w;
       adj[a].push_back({b,w});
       adj[b].push_back({a,w});
    }
    solving(n);

}