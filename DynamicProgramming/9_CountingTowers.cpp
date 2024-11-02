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

void solving(int querries[],int &t){
    int maxElm= *max_element(querries,querries+t);
    ll res[maxElm+1];
    res[1]=2;
    res[0]=1;
    ll nbShape1=1; // ▭
    ll nbShape2=1; // □□
    fi(2,maxElm+1){
        int tmp=nbShape1;
        nbShape1=(nbShape1 + res[i-1])%modulo;
        nbShape2=(res[i-1]+3*(((res[i-1]-tmp)%modulo+modulo)%modulo)%modulo)%modulo;
        res[i]=(nbShape1+nbShape2)%modulo;
    }
    fi(0,t){
        cout<<res[querries[i]]<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int querries[t];
    fi(0,t)
        cin>>querries[i];
    solving(querries,t);
}
