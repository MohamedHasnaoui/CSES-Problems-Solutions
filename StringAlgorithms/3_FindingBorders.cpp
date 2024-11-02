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
    string s;
    cin>>s;
    int sz=s.size();
    build(s);
    vi res;
    fi(0,sz-1){
        if(h[i] == ((h[sz-1]-h[sz-2-i]*p[i+1])%B + B)%B) res.push_back(i+1);
    }
    for(int e:res) cout<<e<<' ';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solving();
}