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
vll dist(1000000,LONG_LONG_MAX);
vll dist2(1000000,LONG_LONG_MAX);

void solving(int& n,int& m){
    priority_queue<tuple<ll,int,int>> q;
    dist[1]=0;
    q.push({0,1,10});
    while(!q.empty()){
        int a=get<1>(q.top());
        int isDiscountUsed = get<2>(q.top());
        q.pop();
        if(processed[a]==11) continue;
        if(processed[a]==1 && isDiscountUsed==1) continue;
        if(processed[a]==10 && isDiscountUsed==10) continue;
        processed[a]+=isDiscountUsed;
        for(auto u:adj[a]){
            int b = u.first,w=u.second;
            if(isDiscountUsed==1) {
                if (dist2[b] > dist2[a] + w) {
                    dist2[b] = dist2[a] + w;
                    q.push({-dist2[b], b, 1});
                }
            }else {
                if (dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                    q.push({-dist[b], b, 10});
                }
                w /= 2;
                if (dist2[b] > dist[a] + w) {
                    dist2[b] = dist[a] + w;
                    q.push({-dist2[b], b, 1});
                }
            }
        }
    }
    cout<<dist2[n]<<' ';
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
        adj[a].push_back({b,c});
    }

    solving(n,m);
}