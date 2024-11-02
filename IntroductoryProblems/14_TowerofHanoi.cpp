//#include<bits/stdc++.h>
//#define fr(i,a,n) for(int i=a;i<n;i++)
//#define ll long long
//using namespace std;
//
//
//void solving(int n,vector<vector<int>>& res,int src=1,int dest=3,int middle=2){
//    if(n!=1){
//        solving(n-1,res,src,middle,dest);
//        res.push_back({src,dest});
//        solving(n-1,res,middle,dest,src);
//    }else{
//        res.push_back({src,dest});
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n;
//    cin>>n;
//    vector<vector<int>> res;
//    solving(n,res);
//    cout<<res.size()<<'\n';
//    for(vector<int> r:res){
//        cout<<r[0]<<' '<<r[1]<<'\n';
//    }
//}
