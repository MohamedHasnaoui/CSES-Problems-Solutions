#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

void solving(int posLights[],int& n,int& x){
    set<int> lights;
    lights.insert(0);lights.insert(x);
    multiset<int> distances;
    distances.insert(x);
    fr(i,0,n){
        auto it = lights.upper_bound(posLights[i]);
        auto tmp = it;
        advance(it,-1);
        distances.erase(distances.find(*tmp - *it));
        lights.insert(posLights[i]);
        distances.insert(posLights[i]-*it);
        distances.insert(*tmp -  posLights[i]);
        cout<<*distances.rbegin()<<' ';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x,n;
    cin>>x>>n;
    int posLights[n];
    fr(i,0,n){
        cin>>posLights[i];
    }
    solving(posLights,n,x);
}
