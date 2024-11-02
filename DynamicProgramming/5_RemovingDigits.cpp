/**

                            * بسم الله الرحمن الرحيم *

    ﴾ رَبِّ اشْرَحْ لِي صَدْرِي * وَيَسِّرْ لِي أَمْرِي * وَاحْلُلْ عُقْدَةً مِّن لِّسَانِي * يَفْقَهُوا قَوْلِي ﴿

**/
#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
#define modulo 1000000007
using namespace std;
int maxDigit(int n){
    vector<int> numbers;
    while(n!=0){
        numbers.push_back(n%10);
        n/=10;
    }
    return *max_element(numbers.begin(),numbers.end());
}
void solving(int& n){
    int i=0;
    while (n!=0){
        n-= maxDigit(n);
        i++;
    }
    cout<<i;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    solving(n);
}
