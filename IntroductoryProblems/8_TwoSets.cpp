#include<bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<n;i++)
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if(n%4!=0 && (n+1)%4!=0){
        cout<<"NO";
        return  0;
    }
    cout<<"YES"<<'\n';
    int nb=n/4;
    if(n%4==0) {
        cout<<2*nb<<'\n';
        fr(i,1,nb+1){
            cout<<i<<' '<<n--<<' ';
        }
        cout<<'\n';
        cout<<2*nb<<'\n';
        fr(i,nb+1,n){
            cout<<i<<' '<<n--<<' ';
        }
        cout<<'\n';
    }else{
        int nb=(n+1)/4;
        cout<<2*(nb-1)+1<<'\n';
        cout<<n--<<' ';
        fr(i,1,nb){
            cout<<i<<' '<<n--<<' ';
        }
        cout<<'\n';
        cout<<2*nb<<'\n';
        fr(i,nb,n){
            cout<<i<<' '<<n--<<' ';
        }
    }

}
