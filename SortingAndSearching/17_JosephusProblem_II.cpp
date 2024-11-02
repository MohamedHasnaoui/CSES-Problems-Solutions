#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


int currentIndex(indexed_set& s,int k,int step){
    int dist = s.size()-k-1;
    if(dist>=step){
        k+=step;
    }else{
        int rest=step-dist-1;
        int go=rest%(s.size());
        k=go;
    }
    return k;
}

void solving(int& n,int& step){
    indexed_set numbers;
    fr(i,1,n+1) numbers.insert(i);
    vector<int> res;
    int k= currentIndex(numbers,0,step);
    while(numbers.size()!=1){
        auto it=numbers.find_by_order(k);
        cout<<*it<<' ';
        if(*it==*numbers.rbegin()) k=1; else k++;
        numbers.erase(it);
        k=currentIndex(numbers,k,step-1);
    }
    cout<<*numbers.find_by_order(0);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,step;
    cin>>n>>step;
    solving(n,step);
}
