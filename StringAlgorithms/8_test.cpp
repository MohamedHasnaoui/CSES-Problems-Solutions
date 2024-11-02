/**

                            * بسم الله الرحمن الرحيم *

    ﴾ رَبِّ اشْرَحْ لِي صَدْرِي * وَيَسِّرْ لِي أَمْرِي * وَاحْلُلْ عُقْدَةً مِّن لِّسَانِي * يَفْقَهُوا قَوْلِي ﴿

**/
#include <bits/stdc++.h>
#define ll long long
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fk(l, r) for(ll k=l;k<r;k++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define ln '\n'
using namespace std;
const ll A= 911382323;
const ll B = 972663749;
const ll modulo= 1e9+7;
const ll modulo1 = 1e9+6;
const ll maxLen = 2e6+5;
int maxWidthRamp(vector<int>& nums) {
    stack<int> monoSt;
    monoSt.push(nums.size()-1);
    for(int j=nums.size()-2;j>=0;j--){
        if(nums[j]>nums[monoSt.top()]){
            monoSt.push(j);
        }
    }
    int ramp=0;
    for(int i=0;i<nums.size()-1;i++){
        stack tmp=monoSt;
        while(!tmp.empty() && nums[tmp.top()]>=nums[i]){
            if(tmp.top()>i) ramp=max(ramp,tmp.top()-i);
            tmp.pop();
        }
    }
    return ramp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> nums = {6,0,8,2,1,5};
    cout<<maxWidthRamp(nums);
}