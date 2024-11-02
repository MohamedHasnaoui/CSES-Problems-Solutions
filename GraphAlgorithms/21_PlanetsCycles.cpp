/**

                            * بسم الله الرحمن الرحيم *

    ﴾ رَبِّ اشْرَحْ لِي صَدْرِي * وَيَسِّرْ لِي أَمْرِي * وَاحْلُلْ عُقْدَةً مِّن لِّسَانِي * يَفْقَهُوا قَوْلِي ﴿

**/
#include <bits/stdc++.h>
#define ll long long
#define fi(l, r) for(ll i=l;i<r;i++)
#define fj(l, r) for(ll j=l;j<r;j++)
#define fir(r, l) for(ll i=r;i>=l;i--)
#define fjr(r, l) for(ll j=r;j>=l;j--)
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define modulo 1000000007
using namespace std;
int adja[200001];
int ind[200001];
int parent[200001];
bool visited[200001];
int result[200001];
bool insideTheCycle;
int startCycle;
void dfs(int s){
    if(result[s]) return;
    if(visited[s]){
        result[s]=ind[s]-ind[parent[s]]-1;
        startCycle=s;
        insideTheCycle=true;
        return;
    }
    visited[s]=true;
    ind[adja[s]]=ind[s]+1;
    if(!visited[adja[s]])
        parent[adja[s]]=s;
    dfs(adja[s]);
    if(insideTheCycle){
        if(s==startCycle){
            insideTheCycle=false;
            return;
        }
        result[s]=result[adja[s]];
        return;
    }
    result[s]=result[adja[s]]+1;
}

void solving(int& n){
    fi(1,n+1){
        if(visited[i]) continue;
        ind[i]=1;
        dfs(i);
    }
    fi(1,n+1){
        cout<<result[i]<<' ';
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    fi(1,n+1) {
        cin>>adja[i];
    }
    solving(n);

}