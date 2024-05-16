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
bool can(vi arr,int k,ll maks){
    int cnt = 1;
    ll res = 0;
    f(i,0,arr.size()){
        if (arr[i]>maks)
        {
            return false;
        }
        
        if (res+arr[i]>maks)
        {
            cnt++;
            res=arr[i];
        }
        else{
            res+=arr[i];
        }
    }

    return cnt<=k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll maks = 0;
    vi arr;
    int n ,k;cin>>n>>k;
    f(i,0,n){
        int a;cin>>a;
        arr.push_back(a);
        maks+=a;
    }
    ll start = 0;
    while (start<maks)
    {
        ll mid = (start+maks)/2;
        if (can(arr,k,mid))
        {
            maks=mid;
        }
        else{
            start=mid+1;
        }
        
    }
    cout <<start<<'\n';
}