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
vi adj[1000000];
int dist1[1000000];
int dist2[1000000];
int result[1000000];
int C[1000000];
int farthestNode=1;
void distanaceFromRoot(int s,int p){
    dist1[s]=0;
    dist2[s]=0;
    for(int u:adj[s]){
        if(u==p) continue;
        distanaceFromRoot(u,s);
        if(dist1[u]+1>dist1[s]){
            dist2[s]=dist1[s];
            dist1[s]=dist1[u]+1;
            C[s]=u;
        }else if(dist1[u]+1>dist2[s]){
            dist2[s]=dist1[u]+1;
        }
    }
}
void getResult(int s,int p){
    for(int u:adj[s]){
        if(u==p) continue;
            if(C[s]==u){
                if(dist1[u]<dist2[s]+1){
                    dist2[u]=dist1[u];
                    dist1[u]=dist2[s]+1;
                    C[u]=s;
                }else{
                    dist2[u]=max(dist2[u],dist2[s]+1);
                }
            }else{
                dist2[u]=dist1[u];
                dist1[u]=dist1[s]+1;
                C[u]=s;
            }
        getResult(u,s);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a,b;
    fi(1,n){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    distanaceFromRoot(1,0);
    result[1]=dist1[1];
    getResult(1,0);
    fi(1,n+1){
        cout<<dist1[i]<<' ';
    }
}