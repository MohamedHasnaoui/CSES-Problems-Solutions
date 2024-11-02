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
int child[100001];
vll minimumPrice(100001,LONG_LONG_MAX);
int nbMinimumPrice[100001];
vi minNbFlights(100001,INT_MAX);
int maxNbFlights[100001];
stack<int> st;
priority_queue<pair<ll,int>> q;

void solving(int& n){
    minimumPrice[1]=0;
    nbMinimumPrice[1]=1;
    minNbFlights[1]=0;
    q.push({0,1});
    while(!q.empty()){
        int s = q.top().second;q.pop();
        if(processed[s]) continue;
        processed[s]=true;
        for(auto u:adj[s]){
            int b=u.first,w=u.second;
            if(minimumPrice[b]>minimumPrice[s]+(ll)w){
                minimumPrice[b]=minimumPrice[s]+(ll)w;
                nbMinimumPrice[b]=nbMinimumPrice[s];
                minNbFlights[b]=minNbFlights[s]+1;
                maxNbFlights[b]=maxNbFlights[s]+1;
                q.push({-minimumPrice[b], b});
            }else if(minimumPrice[b]==minimumPrice[s]+(ll)w){
                nbMinimumPrice[b]=(nbMinimumPrice[s]+nbMinimumPrice[b])%modulo;
                minNbFlights[b]=min(minNbFlights[b],minNbFlights[s]+1);
                maxNbFlights[b]=max(maxNbFlights[b],maxNbFlights[s]+1);
            }
        }
    }
    cout<<minimumPrice[n]<<' '<<nbMinimumPrice[n]<<' '<<minNbFlights[n]<<' '<<maxNbFlights[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b,c;
    cin>>n>>m;
    fi(0,m) {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    solving(n);
}