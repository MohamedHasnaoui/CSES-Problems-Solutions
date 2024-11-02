#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

void solving(int values[],int& n){
    map<int,int> isCounted;
    int sum=0,max=0,ref=1;
    fr(i,0,n){
        if(!isCounted[values[i]] || isCounted[values[i]]<ref){
            isCounted[values[i]]= i+1;
            sum++;
            if(sum>max) max=sum;
        } else{
            sum=i-isCounted[values[i]]+1;
            ref=isCounted[values[i]]+1;
            isCounted[values[i]]=i+1;
        }
    }
    cout<<max;
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
