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
const ll A= 911382323;
const ll B = 972663749;
const ll modulo= 1e9+7;
const ll modulo1 = 1e9+6;
const ll maxLen = 1e6+5;
ll h[maxLen], p[maxLen];
void build(string& s){
    h[0]=s[0];
    p[0]=1;
    fi(1,s.size()){
        h[i]=((A*h[i-1])%B+s[i])%B;
        p[i]=(p[i-1]*A)%B;
    }
}
void solving(){
    string s1,s2;
    cin>>s1>>s2;
    int sz1=s1.size(),sz2=s2.size();
    if(sz1<sz2){
        cout<<0;
        return;
    }
    build(s1);
    ll hash = 0;
    fi(0,sz2){
        hash = (hash + (s2[i]*p[sz2-i-1])%B)%B;
    }
    ll res=0;
    if(hash == h[sz2-1]) res++;
    fi(1,sz1-sz2+1){
        if(hash == ((h[i+sz2-1]-h[i-1]*p[sz2])%B + B)%B) res++;
    }
    cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solving();
}