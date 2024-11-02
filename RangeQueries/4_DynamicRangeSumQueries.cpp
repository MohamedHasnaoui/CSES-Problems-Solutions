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

void constructSt(int st[],int all[],int r,int l=0,int si=0){
    if(l==r){
        st[si]=all[l];
        return;
    }
    int mid=l+(r-l)/2;
    constructSt(st,all,mid,l,2*si+1);
    constructSt(st,all,r,mid+1,2*si+2);
    st[si]=min(st[2*si+1],st[2*si+2]);
}
int getmin(int st[],int l,int r,int sr,int sl=0,int si=0){
    if(r >= sr && l<=sl)
        return st[si];
    if(sr<l || sl>r)
        return INT_MAX;
    int mid=sl+(sr-sl)/2;
    return min(getmin(st,l,r,mid,sl,2*si+1),getmin(st,l,r,sr,mid+1,2*si+2));
}

void update(int st[],int pos,int val,int sr,int sl=0,int si=0){
    if(sl==sr){
        st[si]=val;
        return;
    }
    int mid=sl+(sr-sl)/2 ;
    if(pos<=mid){
        update(st,pos,val,mid,sl,2*si+1);
    }else{
        update(st,pos,val,sr,mid+1,2*si+2);
    }
    st[si]=min(st[2*si+1],st[2*si+2]);
}
void solving(int st[],int& n){
    int a,b,k;
    cin>>k>>a>>b;
    if(k==1){
        update(st,a-1,b,n-1);
    }else{
        cout<<getmin(st,a-1,b-1,n-1)<<'\n';
    }
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
    int st[2*n+2];
    constructSt(st,arr,n-1);
    while(q--){
        solving(st,n);
    }
}