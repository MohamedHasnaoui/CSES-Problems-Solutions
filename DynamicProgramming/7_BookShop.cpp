/**

                            * بسم الله الرحمن الرحيم *

    ﴾ رَبِّ اشْرَحْ لِي صَدْرِي * وَيَسِّرْ لِي أَمْرِي * وَاحْلُلْ عُقْدَةً مِّن لِّسَانِي * يَفْقَهُوا قَوْلِي ﴿

**/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define modulo 1000000007
using namespace std;

void solving(int& n,int x,vector<pair<int,int>>& books){
    vector<ll> res(x+1,0);
    fr(i,0,n){
        for(int j=x;j>=0;j--){
            if(j-books[i].first>=0){
                res[j]=max(res[j],(ll)books[i].second+res[j-books[i].first]);
            }
        }
    }
    cout<<res[x];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> books(n);
    fr(i,0,n){
        int a;
        cin>>a;
        books[i].first=a;
    }
    fr(i,0,n){
        int b;
        cin>>b;
        books[i].second=b;
    }
    solving(n,x,books);
}
