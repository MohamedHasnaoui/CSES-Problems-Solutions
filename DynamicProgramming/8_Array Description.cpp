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

void solving(int& n,int& m,int array[]){
    vector<vector<ll>> res(n,vector<ll>(m+2,0));
    if(array[0]==0){
        fi(1,m+1){
            res[0][i]=1;
        }
    }else res[0][array[0]]=1;

    fi(1,n){
        if(array[i]==0){
            fj(1,m+1){
                res[i][j]=(res[i-1][j]
                +res[i-1][j+1]
                +res[i-1][j-1])%modulo;
            }
        }else{
            res[i][array[i]]=(res[i-1][array[i]]
            +res[i-1][array[i]+1]
            +res[i-1][array[i]-1])%modulo;
        }
    }
    ll result=0;
    fi(1,m+1){
        result=(result + res[n-1][i])%modulo;
    }
    cout<<result;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int array[n];
    fi(0,n){
        cin>>array[i];
    }
    solving(n,m,array);
}
