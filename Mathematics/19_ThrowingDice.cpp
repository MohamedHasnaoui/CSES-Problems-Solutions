/**

                            * بسم الله الرحمن الرحيم *

    ﴾ رَبِّ اشْرَحْ لِي صَدْرِي * وَيَسِّرْ لِي أَمْرِي * وَاحْلُلْ عُقْدَةً مِّن لِّسَانِي * يَفْقَهُوا قَوْلِي ﴿

**/
#include <bits/stdc++.h>
#define ll long long
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fk(l, r) for(ll k=l;k<r;k++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define ln '\n'
using namespace std;
const ll modulo= 1e9+7;
const ll modulo1 = 1e9+6;
vector<vector<ll>> M (6,vector<ll>(6));
vector<vector<ll>> I (6,vector<ll>(6));
void build(){
    fi(0,5){
        fj(1,6){
            if(i==j-1) {
                M[i][j] = 1;
                I[i+1][j] = 1;
            }
        }
    }
    I[0][0]=1;
    fi(0,6) M[5][i]=1;
}
vector<vector<ll>> powerM(ll n){
    if(n==0) return I;
    if(n==1) return M;
    vector<vector<ll>> tmp = powerM(n/2);
    vector<vector<ll>> tmp1 = vector(6,vector<ll>(6));
    fi(0,6){
        fj(0,6){
            ll sum = 0;
            fk(0,6){
                sum=(sum+(tmp[i][k]*tmp[k][j])%modulo)%modulo;
            }
            tmp1[i][j]=sum;
        }
    }
    tmp=tmp1;
    if(n&1) {
        fi(0,6){
            fj(0,6){
                ll sum = 0;
                fk(0,6){
                    sum=(sum+(tmp[i][k]*M[k][j])%modulo)%modulo;;
                }
                tmp1[i][j]=sum;
            }
        }
        tmp=tmp1;
    }
    return tmp;
};
void solving(){
    ll n; cin>>n;
    vector<vector<ll>> X = powerM(n);
    ll V[] = {1,1,2,4,8,16};
    ll result=0;
    fi(0,6) result=(result+(X[0][i]*V[i])%modulo)%modulo;
    cout<<result;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    build();
    solving();
}