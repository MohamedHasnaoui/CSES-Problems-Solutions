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
const ll maxLen = 2e6+5;
int plaindromeSize[maxLen];
void longestPalindrome(string s) {
    string ss="|";
    for(int j=0;j<s.size();j++){
        ss+=s[j];
        ss+="|";
    }
    int center=1;
    string res; int maxSz=0;
    int i=center-1,j=center+1;
    while(center!=ss.size()-1){
        while(i>=0 && j<ss.size()){
            if(ss[i]==ss[j]) plaindromeSize[center]++;
            else break;
            i--;j++;
        }
        if(plaindromeSize[center]==0){
            center++;
            i++;j++;
            continue;
        }
        int lc=center-plaindromeSize[center];
        int rc=center+plaindromeSize[center];
        if(plaindromeSize[center]>maxSz){
            maxSz=plaindromeSize[center];
            res=ss.substr(lc,2*maxSz+1);
            if(j==s.size()-1) break;
        }
        for(int k=center+1;k<=rc;k++){
            int lcc = 2*center-k;
            if(plaindromeSize[lcc]>lcc-lc){
                center=k;
                j=rc+1;i=2*center-j;
                plaindromeSize[center]=j-center-1;
                break;
            }
            else if(plaindromeSize[lcc]==rc-k){
                center=k;
                j=rc+1;i=2*center-j;
                plaindromeSize[center]=plaindromeSize[lcc];
                break;
            }
            else {
                plaindromeSize[i] = plaindromeSize[lcc];
                if(i==rc) {
                    center++;
                    i=center-1;
                    j=center+1;
                }

            }
        }
    }
    for(char ch:res)
        if(ch!='|')
            cout<<ch;
}
vector<int> z(maxLen);
void solving(){
    string l; cin>>l;
    longestPalindrome(l);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solving();
}