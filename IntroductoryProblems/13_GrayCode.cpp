//#include<bits/stdc++.h>
//#define fr(i,a,n) for(int i=a;i<n;i++)
//#define ll long long
//using namespace std;
//
//void solving(int n,char S[]){
//    if(n==0){
//        if(S[0]=='0') S[0]='1';
//        else S[0]='0';
//        cout<<S<<'\n';
//    }
//    else {
//        solving(n-1,S);
//        if (S[n] == '0') S[n] = '1';
//        else S[n] = '0';
//        cout << S << '\n';
//        solving(n-1,S);
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin>>n;
//    char S[n];
//    fr(i,0,n){
//        S[i]='0';
//    }
//    S[n]='\0';
//    cout<<S<<'\n';
//    solving(n-1,S);
//    return 0;
//}
