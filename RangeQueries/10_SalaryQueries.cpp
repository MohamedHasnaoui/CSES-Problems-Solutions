/**

                            * بسم الله الرحمن الرحيم *

    ﴾ رَبِّ اشْرَحْ لِي صَدْرِي * وَيَسِّرْ لِي أَمْرِي * وَاحْلُلْ عُقْدَةً مِّن لِّسَانِي * يَفْقَهُوا قَوْلِي ﴿

**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ll long long
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define modulo 1000000007
#define MAX_VAL 20
using namespace std;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;
indexed_set st;
int arr[200003];
void solving(){
    char c; cin>>c;
    int a,b; cin>>a>>b;
    if(c=='!'){
        st.erase({arr[a - 1], a - 1});
        arr[a-1]=b;
        st.insert({arr[a - 1],a-1});
    }else{
        int e1 = st.order_of_key({a,-1});
        int e2 = st.order_of_key({b,INT_MAX});
        cout<<e2-e1<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    fi(0,n){
        cin>>arr[i];
        st.insert({arr[i],i});
    }
    while(q--){
        solving();
    }
}
