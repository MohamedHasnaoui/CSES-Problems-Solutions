#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

//I used the queue we can also use the sliding window technique

void solving(int values[],int& n,int& target ){
    queue<int> subset;
    int i=0,sum=0,res=0;
    while(i!=n){
        sum+=values[i];
        subset.push(values[i]);
        if(sum==target){
            res++;
        }else if(sum>target){
            while(sum>target){
                sum-=subset.front();
                subset.pop();
            }
            if(sum==target) res++;
        }
        i++;
    }
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,target;
    cin>>n>>target;
    int values[n];
    fr(i,0,n) cin>>values[i];
    solving(values,n,target);
}

