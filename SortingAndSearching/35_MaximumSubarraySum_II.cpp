#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;
void solving(vector<ll>& prefixSum,int& n,int& a,int& b){
    ll maxE,res=LONG_MIN;
    int start=a;
    int end=b;
    multiset<ll>elmnts;
    fr(i,start,end+1) elmnts.insert(prefixSum[i]);
    fr(i,start,n+1){
        maxE=*elmnts.rbegin();
        ll sum=maxE-prefixSum[i-start];
        if(sum>res) res=sum;
        elmnts.erase(elmnts.find(prefixSum[i]));
        if(i+end-start<n){
            elmnts.insert(prefixSum[i+end-start+1]);
        }
    }
    cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    vector<ll> prefixSum(n+1);
    int val;
    prefixSum[0]=0;
    fr(i,1,n+1){
        cin>>val;
        prefixSum[i]=val+prefixSum[i-1];
    }
    solving(prefixSum,n,a,b);
}