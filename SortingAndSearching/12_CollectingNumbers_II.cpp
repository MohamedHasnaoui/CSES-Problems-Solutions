#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int getRounds(int values[],map<int,int>& elmIndex,int n){
    int res=1;
    fr(i,0,n){
        if(elmIndex[values[i]+1]<i && values[i]!=n) res++;
    }
    return res;
}
void solving(int& rounds,int values[],map<int,int>& elmIndex,int& n){
    int a,b;
    cin>>a>>b;
    a--;b--;
    int tmp = values[a];
    values[a]=values[b];
    values[b]=tmp;
    int index1= elmIndex[values[b]-1],index2=elmIndex[values[b]+1];
    int index3= elmIndex[values[a]-1],index4=elmIndex[values[a]+1];
    elmIndex[values[a]]=a;
    elmIndex[values[b]]=b;
    if(values[b]!=1 && index1<a && elmIndex[values[b]-1]>b) rounds++;
    else if(values[b]!=1 && index1>a && elmIndex[values[b]-1]<b) rounds--;
    if(values[b]!=n && values[b]+1!= values[a] && index2<a && elmIndex[values[b]+1]>b) rounds--;
    else if(values[b]!=n && values[b]+1!= values[a] && index2>a && elmIndex[values[b]+1]<b) rounds++;
    if(values[a]!=1 && index3<b && elmIndex[values[a]-1]>a) rounds++;
    else if(values[a]!=1 && index3>b && elmIndex[values[a]-1]<a) rounds--;
    if(values[a]!=n && values[a]+1!= values[b] && index4<b && elmIndex[values[a]+1]>a) rounds--;
    else if(values[a]!=n && values[a]+1!= values[b] &&  index4>b && elmIndex[values[a]+1]<a) rounds++;
    cout<<rounds<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int values[n];
    map<int,int> elmIndex;
    fr(i,0,n){
        cin>>values[i];
        elmIndex[values[i]]=i;
    }
    int rounds=getRounds(values,elmIndex,n);
    while(m--){
        solving(rounds,values,elmIndex,n);
    }
}
