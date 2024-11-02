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

int solving(int n,int m,vector<vector<int>>& res){
    if( m==0 || n==0) return 0;
    if(m==n) return 0;
    int mi = min(n,m);
    int ma = max(n,m);
    if(res[ma][mi]!=-1) return res[ma][mi];
    res[ma][mi]=INT_MAX;
    fi(1,mi+1){
        res[ma][mi]=min(res[ma][mi],solving(i,mi,res)+ solving(mi,ma-i,res)+1);
    }
    fi(1,mi){
        res[ma][mi]=min(res[ma][mi],solving(ma,i,res)+ solving(mi-i,ma,res)+1);
    }
    return res[ma][mi];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> res(max(n,m)+1,vector<int>(min(n,m)+1,-1));
    cout<<solving(m,n,res);
}