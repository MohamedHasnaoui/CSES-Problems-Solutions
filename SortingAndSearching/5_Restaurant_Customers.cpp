#include <bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

void solving(vector<int>& arriveTime,vector<int>& leaveTime ,int& n){
    int k=0;
    int max=0,sum=0;
    for(int i=0;i<n;i++){
        if(arriveTime[i]<=leaveTime[k]) {
            sum++;
            if(sum>max) max=sum;
        }
        else {
            k++;
        }
    }
    cout<<max<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> arriveTime;
    vector<int> LeaveTime;
    fr(i,0,n) {
        int ti,tf;
        cin >> ti >> tf;
        arriveTime.push_back(ti);
        LeaveTime.push_back(tf);
    }
    sort(arriveTime.begin(),arriveTime.end());
    sort(LeaveTime.begin(),LeaveTime.end());
    solving(arriveTime,LeaveTime,n);
}