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
int adj[200001];
ll sum[200001];
ll counts[200001];
const int logK = 18;
ll ancestor[200001][logK];
void build(int& n){
    fi(1,logK){
        fj(1,n+1){
            ancestor[j][i]=ancestor[ancestor[j][i-1]][i-1];
        }
    }
}
void solving(){
    int a,b;
    cin>>a>>b;
    fir(logK,0){
        if(b&1<<i){
            a=ancestor[a][i];
        }
    }
    if(a==0){
        cout<<-1<<'\n';
        return;
    }
    cout<<a<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    fi(2,n+1){
        cin>>ancestor[i][0];
    }
    build(n);
    while(q--){
        solving();
    }
}