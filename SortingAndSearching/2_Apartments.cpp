#include <bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> applicantsSize(n);
    vector<int> apartementsSize(m);
    fr(i,0,n) cin>>applicantsSize[i];
    fr(i,0,m) cin>>apartementsSize[i];
    sort(applicantsSize.begin(),applicantsSize.end());
    sort(apartementsSize.begin(),apartementsSize.end());
    int res=0,i=0,j=0;
    while(i!=n && j!=m){
        if (applicantsSize[i] >= apartementsSize[j] - k &&
            applicantsSize[i] <= apartementsSize[j] + k){
            res++;i++;j++;
        }else if(applicantsSize[i] > apartementsSize[j]) j++;
        else i++;
    }
    cout<<res;
}