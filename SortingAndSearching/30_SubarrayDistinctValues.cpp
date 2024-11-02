#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

ll continousSum(int start,int end){
    ll a=(ll)end-start+1;
    ll res=(ll)(a)*(a+1)/2;
    return res;
}

void solving(int values[],int& n ,int& k){
    unordered_map<int,int>distinctElm;
    ll res=0,start=0,start1=0,end=0;
    while(end!=n){
        distinctElm[values[end]]++;
        while(distinctElm.size()>k){
            distinctElm[values[start]]--;
            if(!distinctElm[values[start]]) distinctElm.erase(values[start]);
            start++;
        }
        if(start>start1){
           res+= continousSum(start1,end-1)- continousSum(start,end-1);
            start1=start;
        }
        end++;
    }
    res+=continousSum(start,end-1);
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int values[n];
    fr(i,0,n) cin>>values[i];
    solving(values,n,k);
}
