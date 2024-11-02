#include <bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

void solving(multiset<int,greater<int>>& tickets ,int& n){
    int clientBudget;
    if(n!=0) {
        cin >> clientBudget;
            auto it = tickets.lower_bound(clientBudget);
            if (it!=tickets.end()) {
                cout << *it<<'\n';
                tickets.erase(it);
                n--;
            } else {
                cout << -1 << '\n';
            }
    }else{
        cout<<-1<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    multiset<int,greater<int>> tickets;
    fr(i,0,n) {
        int inp;
        cin >> inp;
        tickets.insert(inp);
    }
    while(m--) solving(tickets,n);
}