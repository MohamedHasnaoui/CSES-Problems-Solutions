#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

void solving(int values[],int& n){
    multiset<int> towers;
    towers.insert(values[0]);
    fr(i,1,n){
        auto it = towers.upper_bound(values[i]);
        if(it==towers.end()) towers.insert(values[i]);
        else{
            towers.erase(it);
            towers.insert(values[i]);
        }
    }
    cout<<towers.size();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int values[n];
    fr(i,0,n){
        cin>>values[i];
    }
    solving(values,n);
}
