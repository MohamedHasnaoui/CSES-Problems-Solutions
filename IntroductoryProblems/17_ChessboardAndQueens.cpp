#include<bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<n;i++)
#define ll long long
using namespace std;

void solving(int& n,vector<vector<char>>cells,vector<bool>columns,vector<bool>fDiag,vector<bool>sDiag,int& res,int it=0){
    if(it==n) {
        res++;
        return;
    }
    fr(i,0,n){
        if(!(columns[i]||fDiag[i-it+n-1]||sDiag[2*(n-1)-i-it]||cells[it][i]-'*'==0)){
            columns[i]=fDiag[i-it+n-1]=sDiag[2*(n-1)-i-it]=true;
            solving(n,cells,columns,fDiag,sDiag,res,it+1);
            columns[i]=fDiag[i-it+n-1]=sDiag[2*(n-1)-i-it]=false;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n=8;
    vector<vector<char>>cells(n,vector<char>(n));
    fr(i,0,n)
        fr(j,0,n)
            cin>>cells[i][j];
    vector<bool>columns(n,false),fDiag(2*n-1,false),sDiag(2*n-1,false);
    int res=0;
    solving(n,cells,columns,fDiag,sDiag,res);
    cout<<res;
}
