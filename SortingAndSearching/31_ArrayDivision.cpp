#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

bool divideK(int values[],int& n,int& k,ll& mid){
    ll sum=0,nbSubArray=1;
    fr(i,0,n){
        sum+=values[i];
        if(sum>mid){
            sum=(ll)values[i];
            nbSubArray++;
            if(nbSubArray>k) return false;
        }
    }
    return true;
}


void solving(int values[],int& n ,int& k ,ll& sum, ll& max){
    ll start=max,end = sum,res;
    while(start<=end){
        ll mid=start+(end-start)/2 ;
        if(divideK(values,n,k,mid)){
            end=mid-1;
            res=mid;
        }
        else start=mid+1;
    }
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int values[n];
    ll sum=0,max=0;
    fr(i,0,n) {
        cin >> values[i];
        sum+=(ll)values[i];
        if(values[i]>max) max=values[i];
    }
    solving(values,n,k,sum,max);
}
