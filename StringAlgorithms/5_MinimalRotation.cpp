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
vector<int> z(maxLen);
string minimalString(string& s){
    int i=0,ans=0;
    int n=s.size();
    while(i<n/2){
        ans = i;
        int k=i,j=i+1;
        while(j<n && s[k]<=s[j]){
            if(s[k]<s[j]) k=i;
            else k++;
            j++;
        }
        while(i<=k){
            i+=j-k;
        }
    }
    return s.substr(ans,n/2);
}
void solving(){
    string s;
    cin>>s;
    s+=s;
    cout<<minimalString(s);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solving();
}