//#include<bits/stdc++.h>
//#define fr(i,a,n) for(int i=a;i<n;i++)
//#define ll long long
//using namespace std;
//
//
//void solving(string s,int n,map<string,bool> &output,string res=""){
//    if(res.size()==n) {
//        output[res]=true;
//    }
//    fr(i,0,s.size()){
//        res+=s[i];
//        string s1=s;
//        solving(s1.erase(i,1),n,output,res);
//        res.erase(res.size()-1,1);
//    }
//}
//
//int main() {
//    cin.tie(0);
//    cout.tie(0);
//    string s;
//    cin>>s;
//    map<string,bool> output;
//    solving(s,s.size(),output);
//    cout<<output.size()<<'\n';
//    for(auto it=output.begin();it!=output.end();it++) cout<<it->first<<'\n';
//}
