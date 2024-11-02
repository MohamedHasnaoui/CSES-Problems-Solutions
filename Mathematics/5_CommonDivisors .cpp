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
#define ln '\n'
using namespace std;
const ll modulo= 1e9+7;
int maxNumb = 1000000;
int counts[1000000];
int multiples[1000000];
void solving(){
    ll maxGCD;
    fi(1,maxNumb+1){
        for(int j=i;j<=maxNumb;j+=i){
            if(counts[j]) multiples[i]+=counts[j];
        }
        if(multiples[i]>1) maxGCD=i;
    }
    cout<<maxGCD;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    fi(0,n){
        int x;
        cin>>x;
        counts[x]++;
    }
    solving();
}