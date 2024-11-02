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
char arr[1001][1001];
vector<int> adj[1000001];
void bfs(int s,vector<bool>& visited){
    if(visited[s]) {
        return;
    }
    visited[s]=true;
    for(int u: adj[s]){
        bfs(u,visited);
    }
}

void solving(int& n, int& m){
    vector<bool> visited(n*m+1);
    int res = 0;
    fi(1,n+1) {
        fj(1,m+1) {
            int k=m*i-m+j;
            if(!visited[k] && arr[i][j]-'.'==0){
                bfs(k,visited);
                res++;
            }
        }
    }
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    fi(1,n+1) {
        fj(1,m+1) {
            cin >> arr[i][j];
        }
    }
    fi(1,n+1) {
        fj(1,m+1) {
            if(arr[i][j]-'.'==0){
                if(j>1 && arr[i][j-1]-'.'==0){
                    adj[m*i-m+j].push_back(m*i-m+j-1);
                }
                if(j<m && arr[i][j+1]-'.'==0){
                    adj[m*i-m+j].push_back(m*i-m+j+1);
                }
                if(i>1 && arr[i-1][j]-'.'==0){
                    adj[m*i-m+j].push_back(m*(i-1)-m+j);
                }
                if(i<n && arr[i+1][j]-'.'==0){
                    adj[m*i-m+j].push_back(m*(i+1)-m+j);
                }
            }
        }
    }
    solving(n,m);
}