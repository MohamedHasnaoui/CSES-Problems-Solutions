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
vector<vector<char>> adj(1000,vector<char>(1000));
bool visited[1000][1000];
char path[1000][1000];
stack<char> st;
int dist[1000][1000];
void backTrack(int a,int b){
    char ch = path[a][b];
    if(ch!='A'){
        st.push(ch);
        if(ch=='U'){
            backTrack(a+1,b);
        }if(ch=='D'){
            backTrack(a-1,b);
        }if(ch=='L'){
            backTrack(a,b+1);
        }if(ch=='R'){
            backTrack(a,b-1);
        }
    }
}
bool isValidNode(int a,int b,int& n,int& m){
    if(a>=n || b>=m || a<0 || b<0) return false;
    if(visited[a][b] || adj[a][b]-'#'==0) return false;
    return true;
}
void solving(pair<int,int>& start,pair<int,int>& end,int& n,int& m){
   queue<pair<int,int>> q;
   q.push(start);
   visited[start.first][start.second]=true;
   dist[start.first][start.second]=0;
   path[start.first][start.second]='A';
   while(!q.empty()){
       pair<int,int> s = q.front();
       q.pop();
       if(isValidNode(s.first+1,s.second,n,m)){
           q.push({s.first+1,s.second});
           visited[s.first+1][s.second]=true;
           dist[s.first+1][s.second]=dist[s.first][s.second]+1;
           path[s.first+1][s.second]='D';
       }
       if(isValidNode(s.first-1,s.second,n,m)){
           q.push({s.first-1,s.second});
           visited[s.first-1][s.second]=true;
           dist[s.first-1][s.second]=dist[s.first][s.second]+1;
           path[s.first-1][s.second]='U';
       }
       if(isValidNode(s.first,s.second+1,n,m)){
           q.push({s.first,s.second+1});
           visited[s.first][s.second+1]=true;
           dist[s.first][s.second+1]=dist[s.first][s.second]+1;
           path[s.first][s.second+1]='R';
       }
       if(isValidNode(s.first,s.second-1,n,m)){
           q.push({s.first,s.second-1});
           visited[s.first][s.second-1]=true;
           dist[s.first][s.second-1]=dist[s.first][s.second]+1;
           path[s.first][s.second-1]='L';
       }
       if(visited[end.first][end.second]) break;
   }
   if(visited[end.first][end.second]){
       cout<<"YES"<<'\n';
       cout<<dist[end.first][end.second]<<'\n';
       backTrack(end.first,end.second);
       while(!st.empty()){
           cout<<st.top();
           st.pop();
       }
   }else{
       cout<<"NO";
   }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    pair<int,int> start,end;
    cin>>n>>m;
    fi(0,n) {
        fj(0,m){
            cin>>adj[i][j];
            if(adj[i][j]-'A'==0){
                start = {i,j};
            }
            if(adj[i][j]-'B'==0){
                end = {i,j};
            }

        }
    }

    solving(start,end,n,m);
}