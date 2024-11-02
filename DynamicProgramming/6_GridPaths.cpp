/**

                            * بسم الله الرحمن الرحيم *

    ﴾ رَبِّ اشْرَحْ لِي صَدْرِي * وَيَسِّرْ لِي أَمْرِي * وَاحْلُلْ عُقْدَةً مِّن لِّسَانِي * يَفْقَهُوا قَوْلِي ﴿

**/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
#define modulo 1000000007
using namespace std;

void solving(int& n,string grid[]){
    vector<vector<ll>> res(n,vector<ll>(n,0));
    for(int i=n-1;i>=0;i--) {
        if(grid[n-1][i]=='*') break;
            res[n-1][i] = 1;
    }
    for(int i=n-1;i>=0;i--) {
        if(grid[i][n-1]=='*') break;
        res[i][n-1] = 1;
    }
    for(int i=n-2;i>=0;i--) {
        for(int j=n-2;j>=0;j--) {
            if(grid[i][j]!='*') {
                if (grid[i][j + 1] != '*') res[i][j] = res[i][j+1];
                if (grid[i + 1][j] != '*') res[i][j] = (res[i][j] + res[i + 1][j]) % modulo;
            }
        }
    }
    cout<<res[0][0];

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string grid[n];
    fr(i,0,n)
        cin>>grid[i];
    solving(n,grid);
}
