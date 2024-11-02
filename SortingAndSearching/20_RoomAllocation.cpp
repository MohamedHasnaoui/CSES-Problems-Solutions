#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;


void solving( vector<tuple<int,int,int>>& orders,int& n){
    int allocatedRoom[n];
    map<int,stack<int>> rooms;
    multiset<int> roomsLeave;
    roomsLeave.insert(get<1>(orders[0]));
    rooms[get<1>(orders[0])].push(get<2>(orders[0]));
    int roomNumber=1;
    allocatedRoom[get<2>(orders[0])]=roomNumber;
    fr(i,1,n){
        auto it=roomsLeave.lower_bound(get<0>(orders[i]));
        if(it==roomsLeave.begin()) allocatedRoom[get<2>(orders[i])]=++roomNumber;
        else{
            it--;
            allocatedRoom[get<2>(orders[i])]=allocatedRoom[rooms[*it].top()];
            rooms[*it].pop();
            roomsLeave.erase(roomsLeave.find(*it));
        }
        roomsLeave.insert(get<1>(orders[i]));
        rooms[get<1>(orders[i])].push(get<2>(orders[i]));
    }
    cout<<roomNumber<<'\n';
    fr(i,0,n) cout<<allocatedRoom[i]<<' ';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<tuple<int,int,int>> orders;
    fr(i,0,n){
        int a,b;
        cin>>a>>b;
        orders.push_back({a,b,i});
    }
    sort(orders.begin(),orders.end());
    solving(orders,n);
}
