
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
void buildZ(string& s){
    int n = s.size();
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
}
void solving(){
    string s;
    cin>>s;
    buildZ(s);
    int szP = 1;
    vector<int> res;
    fi(0,s.size()){
        if(z[i]+i==s.size()) res.push_back(i);
    }
    for(int e:res) cout<<e<<' ';
    cout<<s.size();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solving();
