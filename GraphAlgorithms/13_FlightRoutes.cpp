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
vector<pair<int,int>> adj[1000000];
int processed[1000000];
char path[1000][1000];
stack<char> st;
vll dist[1000000];
vector<ll> cheapestPrices;
void solving(int& n,int& k){
    priority_queue<pair<ll,int>> q;
    dist[1].push_back(0);
    q.push({0,1});
    while(!q.empty()){
        int a=q.top().second;
        ll v=-q.top().first; q.pop();
        if(processed[a]==k) continue;
        processed[a]++;
        for(auto u:adj[a]){
            int b = u.first,w=u.second;
            q.push({-(v+w), b});
            if(b==n){
                cheapestPrices.push_back((v+(ll)w));
            }
        }
    }
    sort(cheapestPrices.begin(),cheapestPrices.end());
    fi(0,k){
        cout<<cheapestPrices[i]<<' ';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    int a,b,c;
    fi(0,m) {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    solving(n,q);
}