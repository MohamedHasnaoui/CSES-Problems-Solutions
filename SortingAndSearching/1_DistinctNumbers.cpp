#include <bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    fr(i,0,n){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int elm=arr[0];
    int nbDistinctElm=1;
    fr(i,1,n){
        if(arr[i]!=elm){
            nbDistinctElm++;
            elm=arr[i];
        }
    }
    cout<<nbDistinctElm;
}