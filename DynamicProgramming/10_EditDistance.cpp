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

int solving(string& s1,string& s2,int n,int m,vector<vector<int>>& editTable){
    if(editTable[n][m]!=-1) return editTable[n][m];
    editTable[n][m]= min(solving(s1,s2,n-1,m,editTable)+1,
                         min(solving(s1,s2,n,m-1,editTable)+1,
                         solving(s1,s2,n-1,m-1,editTable)+(s1[n-1]!=s2[m-1])));
    return editTable[n][m];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>> editTable(n+1,vector<int>(m+1,-1));
    fi(0,n+1)
        editTable[i][0]=i;
    fi(0,m+1)
        editTable[0][i]=i;
    cout<<solving(s1,s2,n,m,editTable);
}
