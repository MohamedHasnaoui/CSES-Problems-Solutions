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
vector<pair<int,int>> st(1000000);

void contructSt(vector<pair<int,int>>& hotelsRooms,int r,int l=0,int si=0){
    if(r==l){
        st[si]=hotelsRooms[l];
        return;
    }
    int mid=l+(r-l)/2;
    contructSt(hotelsRooms,mid,l,2*si+1);
    contructSt(hotelsRooms,r,mid+1,2*si+2);
    if(st[2*si+1].first>st[2*si+2].first) st[si]=st[2*si+1];
    else st[si]=st[2*si+2];
}
void findHotel(int& nbRooms,int r,int l=0,int si=0){
    if(r==l){
        cout<<st[si].second+1<<'\n';
        st[si].first-=nbRooms;
        return;
    }
    int mid=l+(r-l)/2;
    if(st[2*si+1].first>=nbRooms){
        findHotel(nbRooms,mid,l,2*si+1);
    }else{
        findHotel(nbRooms,r,mid+1,2*si+2);
    }
    if(st[2*si+1].first>st[2*si+2].first) st[si]=st[2*si+1];
    else st[si]=st[2*si+2];
}
void solving(int& n){
    int nbRooms;
    cin>>nbRooms;
    if(nbRooms>st[0].first){
        cout<<0<<'\n';
        return;
    }
    findHotel(nbRooms,n-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> hotelsRooms;
    fi(0,n) {
        int freeRooms;
        cin>>freeRooms;
        hotelsRooms.push_back({freeRooms,i});
    }
    contructSt(hotelsRooms,n-1);
    while(m--){
        solving(n);
    }
}