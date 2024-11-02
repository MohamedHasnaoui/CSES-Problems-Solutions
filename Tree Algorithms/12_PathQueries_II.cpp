/**

                            * بسم الله الرحمن الرحيم *

    ﴾ رَبِّ اشْرَحْ لِي صَدْرِي * وَيَسِّرْ لِي أَمْرِي * وَاحْلُلْ عُقْدَةً مِّن لِّسَانِي * يَفْقَهُوا قَوْلِي ﴿

**/
#include <bits/stdc++.h>
#define ll long long
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define modulo 1000000007
using namespace std;
vi adj[200001];
int values[200001];
int indexNodes[200001];
int subTreeSize[200001];
ll diffArr[200001];
vll treeTraversalArray;
ll segmentTree[2000000];
void dfs1(int s,int p){
    subTreeSize[s]=1;
    for(int u:adj[s]){
        if(u==p) continue;
        indexNodes[u]=treeTraversalArray.size();
        treeTraversalArray.push_back(treeTraversalArray[indexNodes[s]]+(ll)values[u]);
        dfs1(u,s);
        subTreeSize[s]+=subTreeSize[u];
    }
}
void buildDiffArr(int& n){
    diffArr[0]=treeTraversalArray[0];
    fi(1,n){
        diffArr[i]=treeTraversalArray[i]-treeTraversalArray[i-1];
    }
}
void build(int r,int l=0,int si=0){
    if(r==l) {
        segmentTree[si] = (ll)diffArr[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(mid,l,2*si+1);
    build(r,mid+1,2*si+2);
    segmentTree[si]=segmentTree[2*si+1]+segmentTree[2*si+2];
}
ll getSum(int& a,int& b,int r,int l=0,int si=0){
    if(a>r || b<l) return 0ll;
    if(l>=a && r<=b) return  (ll)segmentTree[si];
    int mid = l+(r-l)/2;
    return getSum(a,b,mid,l,2*si+1)+ getSum(a,b,r,mid+1,2*si+2);
}
void update(int& n,int& x,int r,int l=0,int si=0){
    if(l==r) {
        segmentTree[si] += (ll)x;
        return;
    }
    int mid = l+(r-l)/2;
    if(n<=mid)
        update(n,x,mid,l,2*si+1);
    else
        update(n,x,r,mid+1,2*si+2);
    segmentTree[si]=segmentTree[2*si+1]+segmentTree[2*si+2];
}
void solving(int& n){
    int a,b,c;
    cin>>a>>b;
    if(a==1){
        cin>>c;
        int diff = c-values[b];
        values[b]=c;
        update(indexNodes[b],diff,n);
        diff*=-1;
        int index = indexNodes[b]+subTreeSize[b];
        if(index<=n)
            update(index,diff,n);
    }else{
        int findx=0;
        cout<<getSum(findx,indexNodes[b],n)<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int a,b;
    fi(1,n+1){
        cin>>values[i];
    }
    fi(1,n){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    indexNodes[1]=0;
    treeTraversalArray.push_back(values[1]);
    dfs1(1,0);
    buildDiffArr(n);
    n--;
    build(n);
    while(q--){
        solving(n);
    }
}