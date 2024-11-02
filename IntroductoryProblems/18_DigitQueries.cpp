#include<bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<n;i++)
#define ll long long
using namespace std;
ll k;
ll pow10(int exp) {
    ll product = 1;
    for (int i = 0; i < exp; i++) { product *= 10; }
    return product;
}
void solving(){
    cin>>k;
    ll n=1;
    while(k>n*9*pow10(n-1)){
        k-=n*9*pow10(n-1);
        n++;
    }
    long num = (k-1)/n +pow10(n-1);
    int index=(int)((k-1)%n);
    cout<<to_string(num)[index]<<' ';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    while (q--) solving();
}
