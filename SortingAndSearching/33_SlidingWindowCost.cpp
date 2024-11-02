#include <bits/stdc++.h>
#define ll long long
#define fr(i,a,n) for(int i=a;i<n;i++)
using namespace std;

void insertValue(multiset<int>& set1, multiset<int>& set2, int& value,ll& sum1,ll& sum2){
        if(set1.empty()){
            sum1+=(ll)value;
            set1.insert(value);
            return;
        }
        if(*set1.rbegin()>=value){
            set1.insert(value);
            sum1+=(ll)value;
            if(set1.size()>(set2.size()+1)){
                int k=*set1.rbegin();
                set2.insert(k);
                set1.erase(set1.lower_bound(k));
                sum2+=(ll)k;sum1-=(ll)k;
            }
        }else{
            set2.insert(value);
            sum2+=(ll)value;
            if(set2.size()>(set1.size())){
                int k=*set2.begin();
                set1.insert(k);
                set2.erase(set2.lower_bound(k));
                sum1+=(ll)k,sum2-=(ll)k;
            }
        }
}
void deleteValue(multiset<int>& set1, multiset<int>& set2, int& value,ll& sum1,ll& sum2){
    if(value>*set1.rbegin()){
        auto it=set2.lower_bound(value);
        sum2-=(ll)*it;
        set2.erase(it);
    }else {
        auto it=set1.lower_bound(value);
        sum1-=(ll)*it;
        set1.erase(it);
    }
    if(set1.size()>set2.size()+1){
        set2.insert(*set1.rbegin());
        sum2+=(ll)*set1.rbegin();
        sum1-=(ll)*set1.rbegin();
        set1.erase(set1.lower_bound(*set1.rbegin()));
    }else if(set2.size()>(set1.size())){
        set1.insert(*set2.begin());
        sum1+=(ll)*set2.begin();
        sum2-=(ll)*set2.begin();
        set2.erase(set2.lower_bound(*set2.begin()));
    }

}

void solving(int values[],int& n ,int& k){
    multiset<int> set1,set2;
    int first=0,end=k-1;
    ll sum1=0,sum2=0;
    fr(i,0,end) insertValue(set1,set2,values[i],sum1,sum2);
    while(end!=n){
        insertValue(set1,set2,values[end],sum1,sum2);
        ll median = *set1.rbegin();
        cout<<(median*set1.size()-sum1+sum2-median*set2.size())<<' ';
        deleteValue(set1,set2,values[first],sum1,sum2);
        first++,end++;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int values[n];
    fr(i,0,n) {
        cin >> values[i];
    }
    solving(values,n,k);
}
