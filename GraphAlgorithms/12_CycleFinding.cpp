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
vector<tuple<int,int,int>> adj;
vector<int> graph[2501];
bool visited[2501];
int relaxer[2501];
stack<int> st;
vll dist(1000000,0);

void solving(int& n,int& m){
    dist[0]=0;
    int x;
    fi(1,n+1){
        bool shouldBreak=true;
        x=-1;
        for(auto e:adj){
            int a,b,c;
            tie(a,b,c)=e;
            if(dist[b]>dist[a]+(ll)c){
                dist[b]=dist[a]+(ll)c;
                shouldBreak= false;
                relaxer[b]=a;
                x=a;
            }
        }
        if(shouldBreak) break;
    }
    if(x==-1){
        cout<<"NO";
    }else{
        fi(1,n+1){
            x=relaxer[x];
        }
        int s=x;
        st.push(x);
        x=relaxer[x];
        while(x!=s){
            st.push(x);
            x=relaxer[x];
        }
        st.push(s);
        cout<<"YES"<<'\n';
        while(!st.empty()){
            cout<<st.top()<<' ';
            st.pop();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a,b,c;
    fi(0,n+1){
        adj.push_back({0,i,0});
    }
    fi(0,m) {
        cin>>a>>b>>c;
        adj.push_back({a,b,c});
        graph[a].push_back(b);
    }

    solving(n,m);
}