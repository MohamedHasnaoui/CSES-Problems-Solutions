//#include<bits/stdc++.h>
//#define fr(i,a,n) for(int i=a;i<n;i++)
//#define ll long long
//using namespace std;
//
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    string s;
//    cin>>s;
//    std::sort(s.begin(), s.end());
//    string center="";
//    string res="";
//    for(int i=0;i<s.length();i+=2){
//        if(s[i]==s[i+1]){
//            res+=s[i];
//        }else{
//            if(center.length()==0){
//                center=s[i];
//                i--;
//            }else{
//                cout<<"NO SOLUTION";
//                return 0;
//            }
//        }
//    }
//    string s1=res;
//    std::reverse(s1.begin(), s1.end());
//    cout<<res+center+s1;
//
//    return 0;
//}
