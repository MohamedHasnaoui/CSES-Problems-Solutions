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

void build(ll tree[],int arr[],int& n){
    fi(1,n+1){
        tree[i]=0ll;
        int p = (i&-i);
        int start = i-p+1;
        fj(start-1,i){
            tree[i]+=(ll)arr[j];
        }
    }
}

ll add(ll tree[],int& b){
    ll res=0ll;
    while(b>=1){
        res+=tree[b];
        b-=b&-b;
    }
    return res;
}
void update(ll tree[] , int& k,int& val,int& n){
    while(k<=n){
        tree[k]+=(ll)val;
        k+=k&-k;
    }
}

void solving(ll tree[],int arr[],int& n){
    int a,b,k;
    cin>>k>>a>>b;
    if(k==1){
        int val = b - arr[a-1];
        arr[a-1]=b;
        update(tree,a,val,n);
    }else{
        a--;
        cout<<(add(tree,b)-add(tree,a))<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int arr[n+1];
    fi(0,n) {
        cin >> arr[i];
    }
    ll tree[n+1];
    build(tree,arr,n);
    while(q--){
        solving(tree,arr,n);
    }
}