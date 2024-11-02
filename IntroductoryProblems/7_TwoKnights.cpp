//#include<bits/stdc++.h>
//#define fr(i,a,n) for(int i=a;i<n;i++)
//#define ll long long
//using namespace std;
//
//
//int64_t combinaison2(int64_t n){
//    return (n*(n-1))/2;
//}
//
//int64_t possibilities(int64_t n){
//    if(n==1) return 0;
//    else if(n==2) return 6;
//    else if(n==3) return 28;
//    else {
//        return combinaison2(n * n) - (10 + (n - 4) * 4) * (n - 2) - (4 + (n - 4) * 2);
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int64_t n;
//    cin >> n;
//    fr(i,1,n+1){
//        cout<<possibilities(i)<<'\n';
//    }
//}
