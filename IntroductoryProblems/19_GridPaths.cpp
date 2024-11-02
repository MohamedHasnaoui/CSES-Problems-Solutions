#include<bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<n;i++)
#define ll long long
using namespace std;

void solving(string& pattern,array<array<bool,7>,7> visited,int&res,int pathLength=1,int x=0,int y=0){
    if(x==6 && y==0){
        if(pathLength==49) res++;
        return;
    }

    if(x<6 && y<6 && visited[x+1][y+1] && !visited[x][y+1] && !visited[x+1][y]) return;
    if(x<6 && y>0 && visited[x+1][y-1] && !visited[x][y-1] && !visited[x+1][y]) return;
    if(x>0 && y<6 && visited[x-1][y+1] && !visited[x][y+1] && !visited[x-1][y]) return;
    if(x>0 && y>0 && visited[x-1][y-1] && !visited[x][y-1] && !visited[x-1][y]) return;

    if(x>0 && x<6 && !visited[x+1][y] && !visited[x-1][y]&&
       (y==0||y==6|| (visited[x][y-1] && visited[x][y+1]))) return;
    if(y>0 && y<6 && !visited[x][y+1] && !visited[x][y-1]&&
       (x==0||x==6 || (visited[x-1][y] && visited[x+1][y]))) return;

    if((pattern[pathLength-1]=='?')){
        if(x>0 && !visited[x-1][y]){
            visited[x-1][y]=true;
            solving(pattern, visited ,res, pathLength + 1, x - 1, y);
            visited[x-1][y]=false;
        }if(x<6 && !visited[x+1][y]) {
            visited[x+1][y]=true;
            solving(pattern,visited, res, pathLength + 1, x + 1, y);
            visited[x+1][y]=false;
        }if(y>0 &&! visited[x][y-1]) {
            visited[x][y-1]=true;
            solving(pattern,visited, res, pathLength + 1, x, y - 1);
            visited[x][y-1]=false;
        }if(y<6 && !visited[x][y+1]) {
            visited[x][y+1]=true;
            solving(pattern, visited, res, pathLength + 1, x, y + 1);
            visited[x][y+1]=false;
        }
        return;
    }
    if(x>0 && pattern[pathLength-1]=='U' && !visited[x-1][y]) {
        visited[x-1][y]=true;
        solving(pattern, visited ,res, pathLength + 1, x - 1, y);
        visited[x-1][y]=false;
        return;
    }
    if(x<6 &&pattern[pathLength-1]=='D'&&!visited[x+1][y]) {
        visited[x+1][y]=true;
        solving(pattern,visited, res, pathLength + 1, x + 1, y);
        visited[x+1][y]=false;
        return;
    }
    if(y>0 && pattern[pathLength-1]=='L' && !visited[x][y-1]) {
        visited[x][y-1]=true;
        solving(pattern,visited, res, pathLength + 1, x, y - 1);
        visited[x][y-1]=false;
        return;
    }
    if(y<6 && pattern[pathLength-1]=='R'&&!visited[x][y+1]) {
        visited[x][y+1]=true;
        solving(pattern, visited, res, pathLength + 1, x, y + 1);
        visited[x][y+1]=false;
        return;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string pattern;
    cin>>pattern;
    int res=0;
    array<array<bool,7>,7> visited;
    for(auto& row : visited) {
        row.fill(false);
    }
    visited[0][0]=true;
    solving(pattern,visited,res);
    cout<<res;
}