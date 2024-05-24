#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
#define setB(a,i) (a |= (1 << i))
#define unsetB(a,i) (a &= (~(1 << i)))
#define queryB(a,i) (a & (1 << i))
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define all(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define INF_INT 2e9
#define INF_LL 2e18
#define MOD 1000000007


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<pair<int,int> > arr;
    f(i,0,m){
        int a,b;cin>>a>>b;
        arr.push_back(make_pair(min(a,b),max(a,b)));
    }
    f(i,0,m){
        cout<<arr[i].first<<" "<<arr[i].second<<'\n';
    }
}