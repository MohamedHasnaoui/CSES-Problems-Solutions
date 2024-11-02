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

void build(vector<vi>& minq,int arr[],int n){
    fi(0,n){
        minq[0][i]=arr[i];
    }
    for(int i=1;1<<i <=n;i++){
        int tmp = 1<<(i-1);
        for(int j=0;j+tmp<n;j++){
            minq[i][j]=min(minq[i-1][j],minq[i-1][j+tmp]);
        }
    }
}

void solving(vector<vector<int>>& minq){
    int a,b;
    cin>>a>>b;
    int tmp = log2(b-a+1);
    cout<<min(minq[tmp][a-1],minq[tmp][b-(1<<tmp)])<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int arr[n];
    fi(0,n) {
        cin >> arr[i];
    }
    vector<vi> minq(log2(n)+1,vi(n));
    build(minq,arr,n);
    while(q--) solving(minq);
}