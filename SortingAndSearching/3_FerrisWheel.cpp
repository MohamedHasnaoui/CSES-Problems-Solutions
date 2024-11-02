#include <bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x,res=0;
    cin>>n>>x;
    vector<int> children(n);
    fr(i,0,n) cin>>children[i];
    sort(children.begin(),children.end());
    int i=0,j=children.size()-1;
    while(i<=j){
        if(i!=j){
            if(children[i]+children[j]<=x){
                res++;
                i++;j--;
            }else{
                res++;
                j--;
            }
        }else{
            res++;
            i++;
        }
    }
    cout<<res;
}