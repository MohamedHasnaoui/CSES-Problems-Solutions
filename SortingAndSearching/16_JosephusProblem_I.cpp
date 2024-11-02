#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;
void solving(int& n){
    set<int> numbers;
    fr(i,1,n+1) numbers.insert(i);
    auto it=++numbers.begin();
    while(*numbers.rbegin()!=*numbers.begin()){
        cout<<*it<<' ';
        auto tmp = it;
        if(*it==*numbers.rbegin()) it=++numbers.begin();
        else if(*it==*(++numbers.rbegin()))it=numbers.begin();
        else advance(it,2);
        numbers.erase(tmp);
    }
    cout<<*numbers.begin();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    solving(n);
}
