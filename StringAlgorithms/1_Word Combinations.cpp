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
ll nodeCount = 0;
int trie[maxLen][26];
bool isEndOfWord[maxLen];
ll dp[5005];
void insert(string& word){
    int nd = 0;
    for(char& ch:word){
        if(!trie[nd][ch-'a']){
            trie[nd][ch-'a']=++nodeCount;
        }
        nd=trie[nd][ch-'a'];
    }
    isEndOfWord[nd]=true;
}
ll search(string& s,int start){
    ll ways=0,nd=0;
    fi(start,s.size()){
        if(!trie[nd][s[i]-'a']) return ways;
        nd=trie[nd][s[i]-'a'];
        if(isEndOfWord[nd]) ways=(ways+dp[i+1])%modulo;
    }
    return ways;
}
void solving(){
    string s,w; int n;
    cin>>s>>n;
    fi(0,n){
        cin>>w;
        insert(w);
    }
    dp[s.size()]=1;
    fir(s.size()-1,0){
        dp[i]= search(s,i);
    }
    cout<<dp[0];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solving();
}