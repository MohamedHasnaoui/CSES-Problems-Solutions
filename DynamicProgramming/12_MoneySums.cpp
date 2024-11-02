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

void solving(int coins[], int& n){
    int sum = accumulate(coins,coins+n,0);
    vector<bool> possibleSum(sum+1,false);
    possibleSum[0]=true;
    fi(0,n){
        fjr(sum,coins[i]){
            if(possibleSum[j-coins[i]]) possibleSum[j]=true;
        }
    }
    cout<<accumulate(possibleSum.begin(),possibleSum.end(),-1)<<'\n';
    fi(1,sum+1){
        if(possibleSum[i]) cout<<i<<' ';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int coins[n];
    fi(0,n) {
        cin >> coins[i];
    }
    sort(coins,coins+n);
    solving(coins,n);
}