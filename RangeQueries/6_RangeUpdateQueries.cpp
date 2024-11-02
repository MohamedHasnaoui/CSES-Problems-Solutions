/**

                            * بسم الله الرحمن الرحيم *

    ﴾ رَبِّ اشْرَحْ لِي صَدْرِي * وَيَسِّرْ لِي أَمْرِي * وَاحْلُلْ عُقْدَةً مِّن لِّسَانِي * يَفْقَهُوا قَوْلِي ﴿

**/
#include <bits/stdc++.h>
#define ll long
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define modulo 1000000007
using namespace std;
ll st[1000000];
void buildDiffArray(int diffArr[],int arr[],int n){
    diffArr[0]=arr[0];
    fi(1,n){
        diffArr[i]=arr[i]-arr[i-1];
    }
}

void constructSt(int all[],int r,int l=0,int si=0){
    if(l==r){
        st[si]=(ll)all[l];
        return;
    }
    int mid=l+(r-l)/2;
    constructSt(all,mid,l,2*si+1);
    constructSt(all,r,mid+1,2*si+2);
    st[si]=st[2*si+1]+st[2*si+2];
}
ll getsum(int l,int r,int sr,int sl=0,int si=0){
    if(r >= sr && l<=sl)
        return st[si];
    if(sr<l || sl>r)
        return 0ll;
    int mid=sl+(sr-sl)/2;
    ll sum1 = getsum(l,r,mid,sl,2*si+1);
    ll sum2 = getsum(l,r,sr,mid+1,2*si+2);
    return sum1+sum2;
}

void update(int pos,int val,int sr,int sl=0,int si=0){
    if(sl==sr){
        st[si]+=(ll)val;
        return;
    }
    int mid=sl+(sr-sl)/2 ;
    if(pos<=mid){
        update(pos,val,mid,sl,2*si+1);
    }else{
        update(pos,val,sr,mid+1,2*si+2);
    }
    st[si]=st[2*si+1]+st[2*si+2];
}
void solving(int& n){
    int a,b,k;
    cin>>k;
    if(k==1){
        int val;
        cin>>a>>b>>val;
        update(a-1,val,n-1);
        if(b!=n){
            val=-val;
            update(b,val,n-1);
        }
    }else{
        cin>>a;
        cout<<getsum(0,a-1,n-1)<<'\n';
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
    int diffArray[n];
    buildDiffArray(diffArray,arr,n);
    constructSt(diffArray,n-1);
    while(q--){
        solving(n);
    }
}