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
int pre[100001];
int sz[100001];
int maxSize=1;
int result;
int findRepr(int n){
    while(n!=pre[n]) n=pre[n];
    return n;
}
void attach(int n,int m){
    int r1= findRepr(n);
    int r2= findRepr(m);
    if(r1==r2) return;
    if(sz[r1]<sz[r2]) swap(r1,r2);
    sz[r1]=sz[r1]+sz[r2];
    maxSize=max(maxSize,sz[r1]);
    pre[r2]=r1;
    result--;
}
void solving(){
    int a,b;
    cin>>a>>b;
    attach(a,b);
    cout<<result<<' '<<maxSize<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    fi(1,n+1) {
        sz[i] = 1;
        pre[i] = i;
    }
    result = n;
    while(m--)
    solving();

}