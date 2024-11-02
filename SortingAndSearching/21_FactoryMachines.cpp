#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int64_t solving(int64_t times[],int& n,int& t){
    int64_t low=times[0],high= times[n-1]*t;
    int64_t mid;
    int64_t res;
    while (low<=high){
        int64_t products=0;
        mid= low+(high-low)/2;
        fr(i,0,n){
            products+=mid/times[i];
            if(products>=t) break;
        }
        if(products>=t) {
            high = mid - 1;
            res=mid;
        }
        else low=mid+1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin>>n>>t;
    int64_t times[n];
    fr(i,0,n){
        cin>>times[i];
    }
    sort(times,times+n);
    cout<<solving(times,n,t);
}
