/**

                            * بسم الله الرحمن الرحيم *

    ﴾ رَبِّ اشْرَحْ لِي صَدْرِي * وَيَسِّرْ لِي أَمْرِي * وَاحْلُلْ عُقْدَةً مِّن لِّسَانِي * يَفْقَهُوا قَوْلِي ﴿

**/
#include <bits/stdc++.h>
#define ll long
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define modulo 1000000007
using namespace std;

void solving(vector<vll>& preSum2D){
    int x1,y1,x2,y2;
    cin>>y1>>x1>>y2>>x2;
    cout<<preSum2D[y2][x2]-preSum2D[y1-1][x2]-preSum2D[y2][x1-1]+preSum2D[y1-1][x1-1]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int arr[n][n];
    vector<vll> preSum2D(n+1,vll(n+1,0));
    fi(1,n+1) {
        fj(1,n+1){
            char elm;
            cin>>elm;
            if(elm-'*'==0) arr[i-1][j-1]=1; else arr[i-1][j-1]=0;
            preSum2D[i][j]= arr[i-1][j-1]+preSum2D[i-1][j]+preSum2D[i][j-1]-preSum2D[i-1][j-1];
        }
    }
    while(q--){
        solving(preSum2D);
    }
}