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
int st[1000000];
void constructSt(int r,int l=0,int si=0){
    if(l==r){
        st[si]=1;
        return;
    }
    int mid=l+(r-l)/2;
    constructSt(mid,l,2*si+1);
    constructSt(r,mid+1,2*si+2);
    st[si]=st[2*si+1]+st[2*si+2];
}
int getSum(int l,int r,int sr,int sl=0,int si=0){
    if(r >= sr && l<=sl)
        return st[si];
    if(sr<l || sl>r)
        return 0;
    int mid=sl+(sr-sl)/2;
    return getSum(l,r,mid,sl,2*si+1)+getSum(l,r,sr,mid+1,2*si+2);
}

void update(int pos,int sr,int sl=0,int si=0){
    if(sl==sr){
        st[si]=0;
        return;
    }
    int mid=sl+(sr-sl)/2 ;
    if(pos<=mid){
        update(pos,mid,sl,2*si+1);
    }else{
        update(pos,sr,mid+1,2*si+2);
    }
    st[si]=st[2*si+1]+st[2*si+2];
}

int findIndex(int& n,int p,int ones[]){
    int start=0,end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        int sum = getSum(0,mid,n-1);
        if(sum<p){
            start=mid+1;
        }else if(sum>p || ones[mid]==0){
            end=mid-1;
        }else{
            return mid;
        }
    }
    return start;
}

void solving(int& n,int arr[],int ones[]){
   int p;
   cin>>p;
   int index = findIndex(n,p,ones);
   cout<<arr[index]<<'\n';
   update(index,n-1);
   ones[index]=0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n;
    m=n;
    int arr[n];
    int ones[n];
    fi(0,n) {
        cin >> arr[i];
        ones[i]=1;
    }
    constructSt(n-1);
    while(m--){
        solving(n,arr,ones);
    }
}