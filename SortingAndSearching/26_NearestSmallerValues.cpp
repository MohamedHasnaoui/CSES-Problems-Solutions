#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

//I used here the monotonic stack

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    stack<pair<int,int>> values;
    int elm;
    fr(i,0,n){
        cin>>elm;
        while(!values.empty() && values.top().first>=elm) values.pop();
        if(values.empty())cout<<0<<' ';
        else cout<<values.top().second<<' ';
        values.push({elm,i+1});
    }
}

