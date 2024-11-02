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
ll arr[50000];
void solving(){
    int n;
    cin>>n;
    fi(0,n){
        cin>>arr[i];
    }
    ll res=LONG_LONG_MIN;
    fi(0,n){
        int s=i-1,e=i+1;
        int k=1;
        ll sum1=0;
        ll sum2=arr[i];
        if(n&1) swap(sum1,sum2);
        while(s>=0 || e<n){
            if(s!=-1 && (e==n || arr[s]>arr[e])){
                if(k&1) sum1+=arr[s];
                else sum2+=arr[s];
                s--;
                k++;
                continue;
            }
            if(s==-1 || arr[s]<=arr[e]){
                if(k&1) sum1+=arr[e];
                else sum2+=arr[e];
                e++;
                k++;
            }
        }
        cout<<sum1<<' '<<sum2<<'\n';
        res=max(sum1,res);
    }
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solving();
}