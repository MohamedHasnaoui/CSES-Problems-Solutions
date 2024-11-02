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
const int logk = 31;
int succ[200001][logk];
void solving(){
    int a,b;
    cin>>a>>b;
    fi(0,logk){
        if(b&(1<<i)) {
            a = succ[a][i];
        }
    }
    cout<<a<<' ';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    fi(1,n+1) {
        cin>>succ[i][0];
    }
    fj(1,logk){
        fi(1,n+1){
            succ[i][j]=succ[succ[i][j-1]][j-1];
        }
    }
    while(m--){
        solving();
    }

}